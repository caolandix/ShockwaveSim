#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QInputDialog>
#include "../../qcustomplot.h"

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow {
Q_OBJECT

public:
    void axisLabelDoubleClick(QCPAxis *pAxis, QCPAxis::SelectablePart part);
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void titleDoubleClick(QMouseEvent *pEvent, QCPPlotTitle *pTitle);
    void legendDoubleClick(QCPLegend *pLegend, QCPAbstractLegendItem *pItem);
    void selectionChanged();
    void mousePress();
    void mouseWheel();
    void addRandomGraph();
    void removeSelectedGraph();
    void removeAllGraphs();
    void contextMenuRequest(QPoint pos);
    void moveLegend();
    void graphClicked(QCPAbstractPlottable *pPlottable);

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
