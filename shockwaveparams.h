#ifndef SHOCKWAVEPARAMS_H
#define SHOCKWAVEPARAMS_H

#include <QtWidgets>

namespace Ui {
    class ShockwaveParamsDlg;
}


class ShockwaveParams : public QDialog {
    Q_OBJECT
public:
    ShockwaveParams(QWidget *parent = 0);
    ~ShockwaveParams();
private:
    Ui::ShockwaveParamsDlg *m_pUI;

};

#endif // SHOCKWAVEPARAMS_H
