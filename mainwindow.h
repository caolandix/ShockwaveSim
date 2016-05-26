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

    // scientific functions
    double mach(const double velocity, const double speedOfSound);
    double speedOfSound(const double gamma, const double gasConst, const double temperature);

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
    void onShockwaveProperties();
    void onAbout();
    void onPrint();
    void onRedrawGraph();

private:
    Ui::MainWindow *ui;
    ShockwaveDataObj m_sw;
};

#endif // MAINWINDOW_H
