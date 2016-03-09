#include "shockwaveparamsdlg.h"
#include "ui_shockwaveparamsdlg.h"

ShockwaveParamsDlg::ShockwaveParamsDlg(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ShockwaveParamsDlg)
{
    ui->setupUi(this);
}

ShockwaveParamsDlg::~ShockwaveParamsDlg()
{
    delete ui;
}
