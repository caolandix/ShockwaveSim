#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "qcustomplot.h"

#include "shockwavedataobj.h"
#include "shockwaveparamsdlg.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
    Q_OBJECT
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private:
    void setupGraph();
    void setupGraphConnections();
    void setupUIComponents();

    void writeDataFile();
    void ReadRoomElement(QXmlStreamReader &xmlRdr);
    void writeSettingsFile();
    void ReadXMLFile();

    double transcendental_eq_left(const double M1n, const double M2n, const double k, const double gamma);
    double transcendental_eq_right(const double M1n, const double M2n, const double T1, const double T2);
    double calcV2V1(const double T1, const double T2, const double M1n, const double M2n, const double alpha);
    double calcSpeedOfSound(const double T);
signals:
    void redrawGraph();

private slots:
    void titleDoubleClick(QMouseEvent *pEvent, QCPPlotTitle *pTitle);
    void axisLabelDoubleClick(QCPAxis *pAxis, QCPAxis::SelectablePart part);
    void legendDoubleClick(QCPLegend *pLegend, QCPAbstractLegendItem *pItem);
    void selectionChanged();
    void mousePress();
    void mouseWheel();
    void executeGraph();
    void removeSelectedGraph();
    void removeAllGraphs();
    void contextMenuRequest(QPoint pos);
    void moveLegend();
    void graphClicked(QCPAbstractPlottable *pPlottable);
    void onRedrawGraph();

    // QMenu items
    void onShockwaveProperties();
    void onAbout();
    void onPrint();
    void onSave();
    void onSaveAs();

private:
    Ui::MainWindow *ui;
    ShockwaveDataObj m_sw;
    QString m_stgsFile;
    QString m_dataFilename;

};

#endif // MAINWINDOW_H
