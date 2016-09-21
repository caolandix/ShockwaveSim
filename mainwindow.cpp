#include <iostream>

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shockwaveparamsdlg.h"

using namespace std;

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui -> setupUi(this);

    setupGraph();
    setupGraphConnections();
    setupUIComponents();

    m_stgsFile = QString("sw_app_settings.xml");
}

MainWindow::~MainWindow() {
    delete ui;
}

void MainWindow::setupUIComponents() {
    // setup Menu items with actions
    connect(ui ->actionShockwave_Properties, SIGNAL(triggered()), this, SLOT(onShockwaveProperties()));
    connect(ui ->actionExit, SIGNAL(triggered()), this, SLOT(close()));
    connect(ui ->actionSave, SIGNAL(triggered()), this, SLOT(onSave()));
    connect(ui ->actionSave_As, SIGNAL(triggered()), this, SLOT(onSaveAs()));
    connect(ui ->actionAbout, SIGNAL(triggered()), this, SLOT(onAbout()));
    connect(ui ->actionPrint, SIGNAL(triggered()), this, SLOT(onPrint()));
    connect(this, SIGNAL(redrawGraph()), this, SLOT(onRedrawGraph()));
}

void MainWindow::onSave() {
    if (m_dataFilename.length() > 0)
        writeDataFile();
}

void MainWindow::onSaveAs() {
    m_dataFilename = QFileDialog::getSaveFileName(this, tr("Save XML"), ".", tr("XML files (*.xml)"));
    if (m_dataFilename.length() > 0)
        writeDataFile();
}

void MainWindow::writeDataFile() {
    QFile file(m_dataFilename);
    if (file.open(QIODevice::WriteOnly)) {
        QXmlStreamWriter xmlWriter(&file);
        file.close();
    }
}

void MainWindow::writeSettingsFile() {
    QFile file(m_stgsFile);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("Shockwave");

    xmlWriter.writeStartElement("Properties");
    xmlWriter.writeTextElement("State", "statevalue" );
    xmlWriter.writeTextElement("Room", "roomvalue");
    xmlWriter.writeTextElement("Potencial", "potencialvalue");

    xmlWriter.writeEndElement();
    file.close();
}

void MainWindow::ReadXMLFile() {
    QXmlStreamReader xmlRdr;

    QString filename = QFileDialog::getOpenFileName(this, tr("Open XML"), ".", tr("XML files (*.xml)"));

    QFile file(filename);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
            << ": " << qPrintable(file.errorString())
            << std::endl;
    }

    xmlRdr.setDevice(&file);
    xmlRdr.readNext();

    while (!xmlRdr.atEnd()) {
        if (xmlRdr.isStartElement())  {
            if (xmlRdr.name() == "Shockwave")
                xmlRdr.readNext();
            else if (xmlRdr.name() == "Properties") {
                while (!xmlRdr.atEnd()) {
                    if (xmlRdr.isEndElement()) {
                        xmlRdr.readNext();
                        break;
                    }
                    else if (xmlRdr.isCharacters())
                        xmlRdr.readNext();
                    else if (xmlRdr.isStartElement()) {
                        if (xmlRdr.name() == "State")
                            ;//ReadStateElement(xmlRdr);
                        else if (xmlRdr.name() == "Room")
                            ReadRoomElement(xmlRdr);
                        else if (xmlRdr.name() == "Potencial")
                            ;//ReadPotencialElement(xmlRdr);
                        xmlRdr.readNext();
                    }
                    else
                        xmlRdr.readNext();
                }
            }
        }
        else
            xmlRdr.readNext();
        file.close();
        if (xmlRdr.hasError()) {
            std::cerr << "Error: Failed to parse file "
                << qPrintable(filename) << ": "
                << qPrintable(xmlRdr.errorString()) << std::endl;
        }
        else if (file.error() != QFile::NoError) {
            std::cerr << "Error: Cannot read file " << qPrintable(filename)
                << ": " << qPrintable(file.errorString())
                << std::endl;
        }
    }
}

//Example for Room Element
void MainWindow::ReadRoomElement(QXmlStreamReader &xmlRdr) {
    while (!xmlRdr.atEnd()) {
        if (xmlRdr.isEndElement()) {
            xmlRdr.readNext();
            break;
        }
        else if (xmlRdr.isStartElement()) {
            QString roomelement = xmlRdr.readElementText();   //Get the xml value
            xmlRdr.readNext();
            break;
        }
        else if (xmlRdr.isCharacters())
            xmlRdr.readNext();
        else
            xmlRdr.readNext();
    }
}


void MainWindow::setupGraphConnections() {
    // connect slot that ties some axis selections together (especially opposite axes):
    connect(ui ->customPlot, SIGNAL(selectionChangedByUser()), this, SLOT(selectionChanged()));

    // connect slots that takes care that when an axis is selected, only that direction can be dragged and zoomed:
    connect(ui ->customPlot, SIGNAL(mousePress(QMouseEvent *)), this, SLOT(mousePress()));
    connect(ui ->customPlot, SIGNAL(mouseWheel(QWheelEvent *)), this, SLOT(mouseWheel()));

    // make bottom and left axes transfer their ranges to top and right axes:
    connect(ui ->customPlot->xAxis, SIGNAL(rangeChanged(QCPRange)), ui ->customPlot ->xAxis2, SLOT(setRange(QCPRange)));
    connect(ui ->customPlot->yAxis, SIGNAL(rangeChanged(QCPRange)), ui ->customPlot ->yAxis2, SLOT(setRange(QCPRange)));

    // connect some interaction slots:
    connect(ui ->customPlot, SIGNAL(titleDoubleClick(QMouseEvent*,QCPPlotTitle *)), this, SLOT(titleDoubleClick(QMouseEvent *,QCPPlotTitle *)));
    connect(ui ->customPlot, SIGNAL(axisDoubleClick(QCPAxis *, QCPAxis::SelectablePart, QMouseEvent *)), this, SLOT(axisLabelDoubleClick(QCPAxis *, QCPAxis::SelectablePart)));
    connect(ui ->customPlot, SIGNAL(legendDoubleClick(QCPLegend *, QCPAbstractLegendItem *, QMouseEvent *)), this, SLOT(legendDoubleClick(QCPLegend *, QCPAbstractLegendItem *)));

    // connect slot that shows a message in the status bar when a graph is clicked:
    connect(ui ->customPlot, SIGNAL(plottableClick(QCPAbstractPlottable *, QMouseEvent *)), this, SLOT(graphClicked(QCPAbstractPlottable *)));

    // setup policy and connect slot for context menu popup:
    ui ->customPlot ->setContextMenuPolicy(Qt::CustomContextMenu);
    connect(ui ->customPlot, SIGNAL(customContextMenuRequested(QPoint)), this, SLOT(contextMenuRequest(QPoint)));
}

void MainWindow::setupGraph() {
    QFont legendFont = font();
    legendFont.setPointSize(10);

    srand(QDateTime::currentDateTime().toTime_t());
    ui -> customPlot ->setInteractions(QCP::iRangeDrag | QCP::iRangeZoom | QCP::iSelectAxes | QCP::iSelectLegend | QCP::iSelectPlottables);
    ui ->customPlot ->xAxis ->setRange(-8, 8);
    ui ->customPlot ->yAxis->setRange(-5, 5);
    ui ->customPlot ->axisRect() ->setupFullAxesBox();
    ui ->customPlot ->plotLayout() ->insertRow(0);
    ui ->customPlot ->plotLayout() ->addElement(0, 0, new QCPPlotTitle(ui ->customPlot, "Shockwave Simulation"));
    ui ->customPlot ->xAxis ->setLabel("x Axis");
    ui ->customPlot ->yAxis ->setLabel("y Axis");
    ui ->customPlot ->legend ->setVisible(true);
    ui ->customPlot ->legend ->setFont(legendFont);
    ui ->customPlot ->legend ->setSelectedFont(legendFont);
    ui ->customPlot ->legend ->setSelectableParts(QCPLegend::spItems); // legend box shall not be selectable, only legend items

    executeGraph();
}

void MainWindow::titleDoubleClick(QMouseEvent *pEvent, QCPPlotTitle *pTitle) {
    Q_UNUSED(pEvent)

    // Set the plot title by double clicking on it
    bool bOK;
    QString newTitle = QInputDialog::getText(this, "Shockwave Simulation", "New plot title:", QLineEdit::Normal, pTitle ->text(), &bOK);
    if (bOK) {
        pTitle ->setText(newTitle);
        ui ->customPlot ->replot();
    }
}

void MainWindow::axisLabelDoubleClick(QCPAxis *pAxis, QCPAxis::SelectablePart part) {
    if (pAxis) {

        // Set an axis label by double clicking on it
        if (part == QCPAxis::spAxisLabel) {

             // only react when the actual axis label is clicked, not tick label or axis backbone
            bool bOK;
            QString newLabel = QInputDialog::getText(this, "Shockwave Simulation", "New axis label:", QLineEdit::Normal, pAxis ->label(), &bOK);
            if (bOK)  {
                pAxis ->setLabel(newLabel);
                ui ->customPlot ->replot();
            }
        }
    }
}

void MainWindow::legendDoubleClick(QCPLegend *pLegend, QCPAbstractLegendItem *pItem) {

    // Rename a graph by double clicking on its legend item
    Q_UNUSED(pLegend)

    if (pItem ) {

         // only react if item was clicked (user could have clicked on border padding of legend where there is no item, then item is 0)
        QCPPlottableLegendItem *plItem = qobject_cast<QCPPlottableLegendItem *>(pItem);
        bool bOK;
        QString newName = QInputDialog::getText(this, "Shockwave Simulation", "New graph name:", QLineEdit::Normal, plItem ->plottable() ->name(), &bOK);
        if (bOK) {
            plItem ->plottable() ->setName(newName);
            ui ->customPlot ->replot();
        }
    }
}

void MainWindow::selectionChanged() {
    // normally, axis base line, axis tick labels and axis labels are selectable separately, but we want the user only to be able to select the axis as a
    // whole, so we tie the selected states of the tick labels and the axis base line together. However, the axis label shall be selectable individually.
    // The selection state of the left and right axes shall be synchronized as well as the state of the bottom and top axes.
    // Further, we want to synchronize the selection of the graphs with the selection state of the respective legend item belonging to that graph.
    // So the user can select a graph by either clicking on the graph itself or on its legend item.

    // make top and bottom axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui ->customPlot ->xAxis ->selectedParts().testFlag(QCPAxis::spAxis) || ui ->customPlot ->xAxis ->selectedParts().testFlag(QCPAxis::spTickLabels) ||
        ui ->customPlot ->xAxis2 ->selectedParts().testFlag(QCPAxis::spAxis) || ui ->customPlot ->xAxis2 ->selectedParts().testFlag(QCPAxis::spTickLabels)) {
        ui ->customPlot ->xAxis2 ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui ->customPlot ->xAxis ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }
    // make left and right axes be selected synchronously, and handle axis and tick labels as one selectable object:
    if (ui ->customPlot ->yAxis ->selectedParts().testFlag(QCPAxis::spAxis) || ui ->customPlot ->yAxis ->selectedParts().testFlag(QCPAxis::spTickLabels) ||
        ui ->customPlot ->yAxis2 ->selectedParts().testFlag(QCPAxis::spAxis) || ui ->customPlot ->yAxis2 ->selectedParts().testFlag(QCPAxis::spTickLabels)) {
        ui ->customPlot ->yAxis2 ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
        ui ->customPlot ->yAxis ->setSelectedParts(QCPAxis::spAxis|QCPAxis::spTickLabels);
    }

    // synchronize selection of graphs with selection of corresponding legend items:
    for (int i = 0; i < ui ->customPlot ->graphCount(); ++i) {
        QCPGraph *pGraph = ui ->customPlot ->graph(i);
        QCPPlottableLegendItem *pItem = ui ->customPlot ->legend ->itemWithPlottable(pGraph);

        if (pItem ->selected() || pGraph ->selected()) {
            pItem ->setSelected(true);
            pGraph ->setSelected(true);
        }
    }
}

void MainWindow::mousePress() {

    // if an axis is selected, only allow the direction of that axis to be dragged
    // if no axis is selected, both directions may be dragged

    if (ui ->customPlot ->xAxis ->selectedParts().testFlag(QCPAxis::spAxis))
        ui ->customPlot ->axisRect() ->setRangeDrag(ui ->customPlot ->xAxis ->orientation());
    else if (ui ->customPlot ->yAxis ->selectedParts().testFlag(QCPAxis::spAxis))
        ui ->customPlot ->axisRect() ->setRangeDrag(ui ->customPlot ->yAxis ->orientation());
    else
        ui ->customPlot ->axisRect() ->setRangeDrag(Qt::Horizontal | Qt::Vertical);
}

void MainWindow::mouseWheel() {
    // if an axis is selected, only allow the direction of that axis to be zoomed
    // if no axis is selected, both directions may be zoomed

    if (ui ->customPlot ->xAxis ->selectedParts().testFlag(QCPAxis::spAxis))
        ui ->customPlot ->axisRect() ->setRangeZoom(ui ->customPlot ->xAxis ->orientation());
    else if (ui ->customPlot ->yAxis ->selectedParts().testFlag(QCPAxis::spAxis))
        ui ->customPlot ->axisRect() ->setRangeZoom(ui ->customPlot ->yAxis ->orientation());
    else
        ui ->customPlot ->axisRect() ->setRangeZoom(Qt::Horizontal | Qt::Vertical);
}

void MainWindow::executeGraph() {
    int numGraphPoints = 10000;
    // int numGraphPoints = m_sw.numGraphPoints();
    QVector<double> x(numGraphPoints), y(numGraphPoints);
    QVector<double> trans_eq_l(numGraphPoints), trans_eq_r(numGraphPoints);
    QVector<double> disp_sf_x(numGraphPoints), disp_sf_y(numGraphPoints);
    double k = 0.1;
    double radius = 0.3;
    double M1 = 1.9;
    double dy = radius / numGraphPoints;
    double T1 = 300, T2 = 3000;
    double alpha, gamma, lambda = 0.04;
    double yi, xi;
    double M1n, M2n;
    double M1t;
    double V2V1;
    double M2;
    double V2 = calcSpeedOfSound(T2);
    double V1;

    QPen graphPen;
    graphPen.setWidthF(3);

    ui ->customPlot ->addGraph();
    ui ->customPlot ->addGraph();
    ui ->customPlot ->addGraph();
    ui ->customPlot ->addGraph();

    ui ->customPlot ->graph(0) ->setName(QString("Incidence, Mach, and Temperature Ratios in Dual Media"));
    ui ->customPlot ->graph(0) ->setLineStyle(QCPGraph::lsLine);
    ui ->customPlot ->graph(0) ->setScatterStyle(QCPScatterStyle::ssDiamond);

    ui ->customPlot ->graph(1) ->setName(QString("Transcendental Left"));
    ui ->customPlot ->graph(1) ->setLineStyle(QCPGraph::lsNone);
    ui ->customPlot ->graph(1) ->setScatterStyle(QCPScatterStyle::ssCrossCircle);

    ui ->customPlot ->graph(2) ->setName(QString("Transcendental Right"));
    ui ->customPlot ->graph(2) ->setLineStyle(QCPGraph::lsNone);
    ui ->customPlot ->graph(2) ->setScatterStyle(QCPScatterStyle::ssDiamond);

    ui ->customPlot ->graph(3) ->setName(QString("Dispersion Shockwave"));
    ui ->customPlot ->graph(3) ->setLineStyle(QCPGraph::lsLine);
    ui ->customPlot ->graph(3) ->setScatterStyle(QCPScatterStyle::ssCrossCircle);

/*
    for (double dt = 0.05; dt <= 0.5; dt += 0.05) {
        for (int i = 0; i < numGraphPoints; i++) {
            yi = i * dy;
            alpha = asin(yi / radius);
            xi = radius * (1 - cos(alpha));
            M1n = M1 * sin(alpha);
            M2n = 0.00137077 + 2.92163 * alpha - 4.62126 * pow(alpha, 2.0) + 4.24972 * pow(alpha, 3.0) - 1.86993 * pow(alpha, 4.0) + 0.312301 * pow(alpha, 5.0);
            gamma = atan((M1n / M2n) * sqrt(T1 / T2) * tan(alpha));
            V2V1 = calcV2V1(T1, T2, M1n, M2n, alpha);
            x[i] = (xi - k * radius) * (1 - V2V1 * cos(gamma));
            y[i] = yi - V2V1 * (k * radius - xi) * sin(gamma);
            trans_eq_l[i] = transcendental_eq_left(M1n, M2n, k, gamma);
            trans_eq_r[i] = transcendental_eq_right(M1n, M2n, T1, T2);
            M1t = M1 * sin(alpha);
            M2 = sqrt(pow(M2n, 2) * pow(M1t, 2));
            V1 = V2 * (sqrt(T2 / T1) * (M2 / M1));
            disp_sf_x[i] = (xi * (V1 - V2 * cos(gamma))) / V1 + (dt * (V2 * cos(gamma) - V1));
            disp_sf_y[i] = yi - V2 * sin(gamma) * (dt - (xi / V1));
        }
        graphPen.setColor(QColor(Qt::red));
        ui ->customPlot ->graph(1) ->setData(x, trans_eq_l);
        ui ->customPlot ->graph(1) ->setPen(graphPen);

        graphPen.setColor(QColor(Qt::darkGreen));
        ui ->customPlot ->graph(2) ->setData(x, trans_eq_r);
        ui ->customPlot ->graph(2) ->setPen(graphPen);

        graphPen.setColor(QColor(Qt::darkBlue));
        ui ->customPlot ->graph(0) ->setData(x, y);
        ui ->customPlot ->graph(0) ->setPen(graphPen);

        graphPen.setColor(QColor(Qt::cyan));
        ui ->customPlot ->graph(3) ->setData(disp_sf_x, disp_sf_y);
        ui ->customPlot ->graph(3) ->setPen(graphPen);

        ui ->customPlot ->replot();
    }
    */
    int i = 0, j = 0;
    M2n = 1.0;
    for (M1n = 1.0; M1n <= 2.8; M1n += 0.01) {
        trans_eq_l[i++] = transcendental_eq_left(M1n, M2n, k);
        x[j++] = M1n;
    }
    graphPen.setColor(QColor(Qt::red));
    ui ->customPlot ->graph(1) ->setData(x, trans_eq_l);
    ui ->customPlot ->graph(1) ->setPen(graphPen);

    i = 0, j = 0;
    M1n = 0.9;
    for (M2n = 1.0; M2n <= 3.0; M2n += 0.01) {
        trans_eq_r[i++] = transcendental_eq_right(trans_eq_l[i], M2n, T1, T2);
        x[j++] = M2n;
    }
    graphPen.setColor(QColor(Qt::darkGreen));
    ui ->customPlot ->graph(2) ->setData(x, trans_eq_r);
    ui ->customPlot ->graph(2) ->setPen(graphPen);
    ui ->customPlot ->replot();
}
double MainWindow::transcendental_eq_left(const double M1n, const double M2n, const double k) {
    double val1 = 1 / (M1n * (k - 1));
    double val2 = 2 * k * pow(M1n, 2) - (k - 1);
    double val3 = (k - 1) * pow(M1n, 2) + 2;
    double val4 = 2 * k * pow(M2n, 2) - (k - 1);
    double val5 = 2 * k * pow(M1n, 2) - (k - 1);
    double power = k - (1 / 2 * k);
    double retval = (val1) * sqrt(abs(val2 * val3)) * pow(val4 / val5, power) - 1;
    return retval;
}

double MainWindow::transcendental_eq_right(const double M1n, const double M2n, const double T1, const double T2) {
    return M1n * (1 - (1 / pow(M1n, 2))) - M2n * (1 - (1 / pow(M2n, 2))) * sqrt(T2 / T1);
}

double MainWindow::calcSpeedOfSound(const double T) {
    return 643.855 * sqrt(T / 273.15);
}

double MainWindow::calcV2V1(const double T1, const double T2, const double M1n, const double M2n, const double alpha) {
    double cos2x = 0.5 * (1 + cos(2 * alpha));
    double sin2x = 0.5 * (1 - cos(2 * alpha));
    double val1 = cos2x * (T1 / T2) * pow(M2n / M1n, 2);
    double val2 = val1 + sin2x;
    double retVal = sqrt(val2);

    return retVal;

}

void MainWindow::removeSelectedGraph() {
    if (ui ->customPlot ->selectedGraphs().size() > 0) {
        ui ->customPlot ->removeGraph(ui ->customPlot ->selectedGraphs().first());
        ui ->customPlot ->replot();
    }
}

void MainWindow::removeAllGraphs() {
    ui ->customPlot ->clearGraphs();
    ui ->customPlot ->replot();
}

void MainWindow::contextMenuRequest(QPoint pos) {
    QMenu *pMenu = new QMenu(this);
    pMenu ->setAttribute(Qt::WA_DeleteOnClose);

    if (ui->customPlot->legend->selectTest(pos, false) >= 0) {

        // context menu on legend requested
        pMenu ->addAction("Move to top left", this, SLOT(moveLegend())) ->setData((int)(Qt::AlignTop | Qt::AlignLeft));
        pMenu ->addAction("Move to top center", this, SLOT(moveLegend())) ->setData((int)(Qt::AlignTop | Qt::AlignHCenter));
        pMenu ->addAction("Move to top right", this, SLOT(moveLegend())) ->setData((int)(Qt::AlignTop | Qt::AlignRight));
        pMenu ->addAction("Move to bottom right", this, SLOT(moveLegend())) ->setData((int)(Qt::AlignBottom | Qt::AlignRight));
        pMenu ->addAction("Move to bottom left", this, SLOT(moveLegend())) ->setData((int)(Qt::AlignBottom | Qt::AlignLeft));
    }
    else {

        // general context menu on graphs requested
        if (ui ->customPlot ->selectedGraphs().size() > 0)
            pMenu ->addAction("Remove selected graph", this, SLOT(removeSelectedGraph()));
        if (ui ->customPlot ->graphCount() > 0)
            pMenu ->addAction("Remove all graphs", this, SLOT(removeAllGraphs()));
    }
    pMenu ->popup(ui ->customPlot ->mapToGlobal(pos));
}

void MainWindow::moveLegend() {
    QAction *pAction = qobject_cast<QAction *>(sender());
    if (pAction) {

        // make sure this slot is really called by a context menu action, so it carries the data we need
        bool bOK;
        int dataInt = pAction ->data().toInt(&bOK);
        if (bOK) {
            ui ->customPlot ->axisRect() ->insetLayout() ->setInsetAlignment(0, (Qt::Alignment)dataInt);
            ui ->customPlot ->replot();
        }
    }
}

void MainWindow::graphClicked(QCPAbstractPlottable *pPlottable) {
    ui ->statusBar ->showMessage(QString("Clicked on graph '%1'.").arg(pPlottable ->name()), 1000);
}

void MainWindow::onShockwaveProperties() {
    ShockwaveParamsDlg dlg(this);
    dlg.setShockwaveDataProps(m_sw);

    if (dlg.exec() == QDialog::Accepted) {
        dlg.getShockwaveDataProps(m_sw);
        emit redrawGraph();
    }
}

void MainWindow::onAbout() {

}

void MainWindow::onPrint() {

}

void MainWindow::onRedrawGraph() {

}
