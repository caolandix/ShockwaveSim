#ifndef SHOCKWAVEPARAMSDLG_H
#define SHOCKWAVEPARAMSDLG_H

#include <QDialog>

namespace Ui {
class ShockwaveParamsDlg;
}

class ShockwaveParamsDlg : public QDialog
{
    Q_OBJECT

public:
    explicit ShockwaveParamsDlg(QWidget *parent = 0);
    ~ShockwaveParamsDlg();

private:
    Ui::ShockwaveParamsDlg *ui;
};

#endif // SHOCKWAVEPARAMSDLG_H
