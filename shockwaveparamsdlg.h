#ifndef SHOCKWAVEPARAMSDLG_H
#define SHOCKWAVEPARAMSDLG_H

#include <QDialog>
#include "shockwavedataobj.h"

namespace Ui {
    class ShockwaveParamsDlg;
}

class ShockwaveParamsDlg : public QDialog {
    Q_OBJECT
public:
    explicit ShockwaveParamsDlg(QWidget *parent = 0);
    ~ShockwaveParamsDlg();

    void setShockwaveDataProps(const ShockwaveDataObj &);
    void getShockwaveDataProps(ShockwaveDataObj &);

private:
    Ui::ShockwaveParamsDlg *ui;
};

#endif // SHOCKWAVEPARAMSDLG_H
