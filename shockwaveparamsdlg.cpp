#include "shockwaveparamsdlg.h"
#include "ui_shockwaveparamsdlg.h"
#include "shockwavedataobj.h"

ShockwaveParamsDlg::ShockwaveParamsDlg(QWidget *parent) : QDialog(parent), ui(new Ui::ShockwaveParamsDlg) {
    ui ->setupUi(this);
}

ShockwaveParamsDlg::~ShockwaveParamsDlg() {
    delete ui;
}

void ShockwaveParamsDlg::onOKButtonClicked() {
    setResult(QDialog::Accepted);
}

void ShockwaveParamsDlg::onCancelButtonClicked() {
    setResult(QDialog::Rejected);
}

void ShockwaveParamsDlg::setShockwaveDataProps(const ShockwaveDataObj &obj) {
    ui ->edtMagFieldStr ->setText(QString::number(obj.B()));
    ui ->edtConstPressSpecificHeat ->setText(QString::number(obj.Cp()));
    ui ->edtConstVolSpecificHeat ->setText(QString::number(obj.Cv()));
    ui ->edtInternalEnergy ->setText(QString::number(obj.e()));
    ui ->edtEnthalpy ->setText(QString::number(obj.h()));
    ui ->edtCurrent ->setText(QString::number(obj.I()));
    ui ->edtPressure ->setText(QString::number(obj.p()));
    ui ->edtRadialDist ->setText(QString::number(obj.r()));
    ui ->edtEntropy ->setText(QString::number(obj.s()));
    ui ->edtTemperature ->setText(QString::number(obj.T()));
    ui ->edtTime ->setText(QString::number(obj.t()));
    ui ->edtVelocity ->setText(QString::number(obj.u()));
    ui ->edtSpecificVol ->setText(QString::number(obj.v()));
    ui ->edtShockDetSpeed ->setText(QString::number(obj.W()));
    ui ->edtPosition ->setText(QString::number(obj.x()));
}

void ShockwaveParamsDlg::getShockwaveDataProps(ShockwaveDataObj &obj) {
    obj.B(ui ->edtMagFieldStr ->text().toDouble());
    obj.Cp(ui ->edtConstPressSpecificHeat ->text().toDouble());
    obj.Cv(ui ->edtConstVolSpecificHeat ->text().toDouble());
    obj.e(ui ->edtInternalEnergy ->text().toDouble());
    obj.h(ui ->edtEnthalpy ->text().toDouble());
    obj.I(ui ->edtCurrent ->text().toDouble());
    obj.p(ui ->edtPressure ->text().toDouble());
    obj.r(ui ->edtRadialDist ->text().toDouble());
    obj.s(ui ->edtEntropy ->text().toDouble());
    obj.T(ui ->edtTemperature ->text().toDouble());
    obj.t(ui ->edtTime ->text().toDouble());
    obj.u(ui ->edtVelocity ->text().toDouble());
    obj.v(ui ->edtSpecificVol ->text().toDouble());
    obj.W(ui ->edtShockDetSpeed ->text().toDouble());
    obj.x(ui ->edtPosition ->text().toDouble());
}
