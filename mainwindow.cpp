#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "shockwaveparamsdlg.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent), ui(new Ui::MainWindow) {
    ui -> setupUi(this);

    setupGraph();
    setupGraphConnections();
    setupUIComponents();

    m_stgsFile = QString("swAppSettings.xml");
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
    writeDataFile();
}

void MainWindow::onSaveAs() {
    m_dataFilename = QFileDialog::getSaveFileName(this, tr("Save Xml"), ".", tr("Xml files (*.xml)"));
}

void MainWindow::writeSettingsFile() {


    QFile file(m_stgsFile);
    file.open(QIODevice::WriteOnly);

    QXmlStreamWriter xmlWriter(&file);
    xmlWriter.setAutoFormatting(true);
    xmlWriter.writeStartDocument();

    xmlWriter.writeStartElement("LAMPS");

    xmlWriter.writeStartElement("LIGHT1");
    xmlWriter.writeTextElement("State", "statevalue" );
    xmlWriter.writeTextElement("Room", "roomvalue");
    xmlWriter.writeTextElement("Potencial", "potencialvalue");

    xmlWriter.writeEndElement();

        file.close();
}

void MyXMLClass::ReadXMLFile() {
        QXmlStreamReader Rxml;

        QString filename = QFileDialog::getOpenFileName(this,
                                   tr("Open Xml"), ".",
                                   tr("Xml files (*.xml)"));

    QFile file(filename);
        if (!file.open(QFile::ReadOnly | QFile::Text))
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;

    }

    Rxml.setDevice(&file);
    Rxml.readNext();

    while(!Rxml.atEnd())
    {
        if(Rxml.isStartElement())
        {
            if(Rxml.name() == "LAMPS")
            {
                Rxml.readNext();
            }
            else if(Rxml.name() == "LIGHT1")
            {
                while(!Rxml.atEnd())
                            {
                             if(Rxml.isEndElement())
                             {
                             Rxml.readNext();
                             break;
                             }
                             else if(Rxml.isCharacters())
                             {
                             Rxml.readNext();
                             }
                             else if(Rxml.isStartElement())
                             {
                             if(Rxml.name() == "State")
                             {
                              ReadStateElement();
                             }
                             else if(Rxml.name() == "Room")
                             {
                              ReadRoomElement();
                             }
                             else if(Rxml.name() == "Potencial")
                             {
                                  ReadPotencialElement();
                             }
                             Rxml.readNext();
                         }
                         else
                         {
                         Rxml.readNext();
                         }
                    }
            }
        }
    else
    {
        Rxml.readNext();
    }

    file.close();

        if (Rxml.hasError())
    {
       std::cerr << "Error: Failed to parse file "
                 << qPrintable(filename) << ": "
                 << qPrintable(Rxml.errorString()) << std::endl;
        }
    else if (file.error() != QFile::NoError)
    {
        std::cerr << "Error: Cannot read file " << qPrintable(filename)
                  << ": " << qPrintable(file.errorString())
                  << std::endl;
    }
}

//Example for Room Element
void MyXMLClass::ReadRoomElement() {
    while (!Rxml.atEnd()) {
        if (Rxml.isEndElement()) {
            Rxml.readNext();
            break;
        }
        else if (Rxml.isStartElement()) {
            QString roomelement = Rxml.readElementText();   //Get the xml value
            Rxml.readNext();
            break;
        }
        else if (Rxml.isCharacters()) {
            Rxml.readNext();
        }
        else {
            Rxml.readNext();
        }
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
    int numGraphPoints = 100;
    QVector<double> x(numGraphPoints), y(numGraphPoints);
    double k = 0.1;
    double radius = 0.3;
    double N = 100;
    double M1 = 1.9;
    double dy = radius / N;
    double T1 = 300, T2 = 3000;
    double alpha, gamma, lambda = 0.04;
    double yi, xi;
    double M1n, M2n;
    double V2V1;

    for (int i = 0; i < numGraphPoints; i++) {
        yi = i * dy;
        alpha = asin(yi / radius);
        xi = radius * (1 - cos(alpha));
        M1n = M1 * sin(alpha);
        M2n = 0.00137077 + 2.92163 * alpha - 4.62126 * pow(alpha, 2.0) + 4.24972 * pow(alpha, 3.0) - 1.86993 * pow(alpha, 4.0) + 0.312301 * pow(alpha, 5.0);
        gamma = atan((M1n / M2n) * sqrt(T1 / T2) * tan(alpha));
        V2V1 = sqrt((T2 / T1) * (pow(M2n / M1n, 2) * exp(-pow(yi, 2) / pow(lambda, 2)) * (pow(cos(alpha), 2) + pow(sin(alpha), 2))));
        x[i] = (xi - k * radius) * (1 - V2V1 * cos(gamma));
        y[i] = yi - V2V1 * (k * radius - xi) * sin(gamma);
    }
    QPen graphPen;
    ui ->customPlot ->addGraph();
    ui ->customPlot ->graph() ->setName(QString("New graph %1").arg(ui ->customPlot ->graphCount() - 1));
    ui ->customPlot ->graph() ->setData(x, y);
    ui ->customPlot ->graph() ->setLineStyle(QCPGraph::lsNone);
    ui ->customPlot ->graph() ->setScatterStyle(QCPScatterStyle::ssDot);
    graphPen.setColor(QColor(Qt::red));
    graphPen.setWidthF(3);
    ui ->customPlot ->graph() ->setPen(graphPen);
    ui ->customPlot ->replot();
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
    QAction *pAction = NULL;
    if (pAction = qobject_cast<QAction *>(sender())) {

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
