#include "shockwaveparamsdlg.h"
#include "ui_shockwaveparamsdlg.h"

ShockwaveParamsDlg::ShockwaveParamsDlg(QWidget *parent) : QDialog(parent), ui(new Ui::ShockwaveParamsDlg) {
    ui ->setupUi(this);
}

ShockwaveParamsDlg::~ShockwaveParamsDlg() {
    delete ui;
}

void ShockwaveParamsDlg::setShockwaveDataProps(const ShockwaveDataObj &obj) {
    ui ->edtSoundSpeed = obj.();
    ui ->edtMagFieldStr = obj.();
    ui ->edtConstPressSpecificHeat = obj.();
    ui ->edtConstVolSpecificHeat = obj.();
    ui ->edtCharisticLinesPlus = obj.();
    ui ->edtCharisticLinesMinus = obj.();
    ui ->edtInternalEnergy = obj.();
    ui ->edtNonDimHeatRelParam = obj.();
    ui ->edtEnthalpy = obj.();
    ui ->edtCurrent = obj.();
    ui ->edtReimannInvariantPlus = obj.();
    ui ->edtReimannInvariantMinus = obj.();
    ui ->edtWidthDetonationWaveSys = obj.();
    ui ->edtMach = obj.();
    ui ->edtPressure = obj.();
    ui ->edtMagPressureParam = obj.();
    ui ->edtHeatRelParam = obj.();
    ui ->edtIdealGasConst = obj.();
    ui ->edtRadialDist = obj.();
    ui ->edtEntropy = obj.();
    ui ->edtTemperature = obj.();
    ui ->edtTime = obj.();
    ui ->edtVelocity = obj.();
    ui ->edtSpecificVol = obj.();
    ui ->edtShockDetSpeed = obj.();
    ui ->edtPosition = obj.();
    ui ->edtAlpha = obj.();
    ui ->edtBeta = obj.();
    ui ->edtGamma = obj.();
    ui ->edtMu0 = obj.();
    ui ->edtRho = obj.();
    ui ->edtSigma = obj.();
}

void ShockwaveParamsDlg::getShockwaveDataProps(ShockwaveDataObj &obj) {
    obj.a(ui ->edtSoundSpeed);
    obj.B(ui ->edtMagFieldStr);
    obj.Cp(ui ->edtConstPressSpecificHeat);
    obj.Cv(ui ->edtConstVolSpecificHeat);
    obj.Cplus(ui ->edtCharisticLinesPlus);
    obj.Cminus(ui ->edtCharisticLinesMinus);
    obj.e(ui ->edtInternalEnergy);
    obj.H(ui ->edtNonDimHeatRelParam);
    obj.h(ui ->edtEnthalpy);
    obj.I(ui ->edtCurrent);
    obj.(ui ->edtReimannInvariantPlus);
    obj.(ui ->edtReimannInvariantMinus);
    obj.L(ui ->edtWidthDetonationWaveSys);
    obj.M(ui ->edtMach);
    obj.p(ui ->edtPressure);
    obj.Q(ui ->edtMagPressureParam);
    obj.q(ui ->edtHeatRelParam);
    obj.R(ui ->edtIdealGasConst);
    obj.r(ui ->edtRadialDist);
    obj.s(ui ->edtEntropy);
    obj.T(ui ->edtTemperature);
    obj.t(ui ->edtTime);
    obj.u(ui ->edtVelocity);
    obj.v(ui ->edtSpecificVol);
    obj.W(ui ->edtShockDetSpeed);
    obj.x(ui ->edtPosition);
    obj.(ui ->edtAlpha);
    obj.(ui ->edtBeta);
    obj.gamma(ui ->edtGamma);
    obj.mu0(ui ->edtMu0);
    obj.rho(ui ->edtRho);
    obj.sigma(ui ->edtSigma);
}
