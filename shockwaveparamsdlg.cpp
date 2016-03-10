#include "shockwaveparamsdlg.h"
#include "ui_shockwaveparamsdlg.h"

ShockwaveParamsDlg::ShockwaveParamsDlg(QWidget *parent) : QDialog(parent), ui(new Ui::ShockwaveParamsDlg) {
    ui ->setupUi(this);
}

ShockwaveParamsDlg::~ShockwaveParamsDlg() {
    delete ui;
}

void ShockwaveParamsDlg::setShockwaveDataProps(const ShockwaveDataObj &obj) {
    ui ->edtMagFieldStr ->setText(obj.B();
    ui ->edtConstPressSpecificHeat ->setText(obj.Cp());
    ui ->edtConstVolSpecificHeat ->setText(obj.Cv());
    ui ->edtInternalEnergy ->setText(obj.e());
    ui ->edtEnthalpy ->setText(obj.h());
    ui ->edtCurrent ->setText(obj.I());
    ui ->edtPressure ->setText(obj.p());
    ui ->edtRadialDist ->setText(obj.r());
    ui ->edtEntropy ->setText(obj.s());
    ui ->edtTemperature ->setText(obj.T());
    ui ->edtTime ->setText(obj.t());
    ui ->edtVelocity ->setText(obj.u());
    ui ->edtSpecificVol ->setText(obj.v());
    ui ->edtShockDetSpeed ->setText(obj.W());
    ui ->edtPosition ->setText(obj.x());
}

void ShockwaveParamsDlg::getShockwaveDataProps(ShockwaveDataObj &obj) {
    obj.B(ui ->edtMagFieldStr ->text()::toDouble());
    obj.Cp(ui ->edtConstPressSpecificHeat);
    obj.Cv(ui ->edtConstVolSpecificHeat);
    obj.e(ui ->edtInternalEnergy);
    obj.h(ui ->edtEnthalpy);
    obj.I(ui ->edtCurrent);
    obj.p(ui ->edtPressure);
    obj.r(ui ->edtRadialDist);
    obj.s(ui ->edtEntropy);
    obj.T(ui ->edtTemperature);
    obj.t(ui ->edtTime);
    obj.u(ui ->edtVelocity);
    obj.v(ui ->edtSpecificVol);
    obj.W(ui ->edtShockDetSpeed);
    obj.x(ui ->edtPosition);
}
