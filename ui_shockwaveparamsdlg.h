/********************************************************************************
** Form generated from reading UI file 'shockwaveparamsdlg.ui'
**
** Created by: Qt User Interface Compiler version 5.5.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SHOCKWAVEPARAMSDLG_H
#define UI_SHOCKWAVEPARAMSDLG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>

QT_BEGIN_NAMESPACE

class Ui_ShockwaveParamsDlg
{
public:
    QDialogButtonBox *btnsOkayCancel;
    QLabel *label;
    QLineEdit *edtMagFieldStr;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_9;
    QLabel *label_10;
    QLabel *label_11;
    QLabel *label_12;
    QLabel *label_13;
    QLabel *label_14;
    QLabel *label_15;
    QLabel *label_16;
    QLabel *label_17;
    QLabel *label_18;
    QLabel *label_19;
    QLabel *label_20;
    QLabel *label_21;
    QLineEdit *edtConstPressSpecificHeat;
    QLineEdit *edtCharLinesPlus;
    QLineEdit *edtCharLinesMinus;
    QLineEdit *edtInternalEnergy;
    QLineEdit *edtNonDimHeatRel;
    QLineEdit *edtEnthalpy;
    QLineEdit *edtCurrent;
    QLineEdit *edtWidthOfDetonation;
    QLineEdit *edtMachNum;
    QLineEdit *edtConstVolSpecificHeat;
    QLabel *label_23;
    QLabel *label_22;
    QLineEdit *edtPressure;
    QLineEdit *edtGasType;
    QLineEdit *edtHeatRel;
    QLineEdit *edtMagPress;
    QLineEdit *edtTempR1;
    QLineEdit *edtEntropy;
    QLineEdit *edtRadialDist;
    QLineEdit *edtShockDetSpeed;
    QLineEdit *edtSpecificVol;
    QLineEdit *edtVelocity;
    QLineEdit *edtTime;
    QLineEdit *edtPosition;
    QLabel *label_24;
    QLineEdit *edtTempR2;

    void setupUi(QDialog *ShockwaveParamsDlg)
    {
        if (ShockwaveParamsDlg->objectName().isEmpty())
            ShockwaveParamsDlg->setObjectName(QStringLiteral("ShockwaveParamsDlg"));
        ShockwaveParamsDlg->resize(601, 640);
        btnsOkayCancel = new QDialogButtonBox(ShockwaveParamsDlg);
        btnsOkayCancel->setObjectName(QStringLiteral("btnsOkayCancel"));
        btnsOkayCancel->setGeometry(QRect(150, 600, 293, 28));
        btnsOkayCancel->setOrientation(Qt::Horizontal);
        btnsOkayCancel->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        btnsOkayCancel->setCenterButtons(true);
        label = new QLabel(ShockwaveParamsDlg);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 10, 140, 16));
        edtMagFieldStr = new QLineEdit(ShockwaveParamsDlg);
        edtMagFieldStr->setObjectName(QStringLiteral("edtMagFieldStr"));
        edtMagFieldStr->setGeometry(QRect(190, 10, 113, 22));
        label_2 = new QLabel(ShockwaveParamsDlg);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 40, 166, 16));
        label_3 = new QLabel(ShockwaveParamsDlg);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 70, 159, 16));
        label_4 = new QLabel(ShockwaveParamsDlg);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(10, 100, 131, 16));
        label_5 = new QLabel(ShockwaveParamsDlg);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 160, 101, 16));
        label_6 = new QLabel(ShockwaveParamsDlg);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 130, 131, 16));
        label_7 = new QLabel(ShockwaveParamsDlg);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(10, 190, 181, 16));
        label_8 = new QLabel(ShockwaveParamsDlg);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(10, 220, 61, 16));
        label_9 = new QLabel(ShockwaveParamsDlg);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(10, 250, 51, 16));
        label_10 = new QLabel(ShockwaveParamsDlg);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(10, 280, 161, 16));
        label_11 = new QLabel(ShockwaveParamsDlg);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(10, 340, 151, 16));
        label_12 = new QLabel(ShockwaveParamsDlg);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(10, 310, 140, 16));
        label_13 = new QLabel(ShockwaveParamsDlg);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(10, 370, 151, 16));
        label_14 = new QLabel(ShockwaveParamsDlg);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(10, 400, 81, 16));
        label_15 = new QLabel(ShockwaveParamsDlg);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(10, 430, 61, 16));
        label_16 = new QLabel(ShockwaveParamsDlg);
        label_16->setObjectName(QStringLiteral("label_16"));
        label_16->setGeometry(QRect(10, 460, 101, 16));
        label_17 = new QLabel(ShockwaveParamsDlg);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(10, 490, 151, 16));
        label_18 = new QLabel(ShockwaveParamsDlg);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(10, 520, 151, 16));
        label_19 = new QLabel(ShockwaveParamsDlg);
        label_19->setObjectName(QStringLiteral("label_19"));
        label_19->setGeometry(QRect(330, 10, 151, 16));
        label_20 = new QLabel(ShockwaveParamsDlg);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(330, 70, 151, 16));
        label_21 = new QLabel(ShockwaveParamsDlg);
        label_21->setObjectName(QStringLiteral("label_21"));
        label_21->setGeometry(QRect(330, 40, 151, 16));
        edtConstPressSpecificHeat = new QLineEdit(ShockwaveParamsDlg);
        edtConstPressSpecificHeat->setObjectName(QStringLiteral("edtConstPressSpecificHeat"));
        edtConstPressSpecificHeat->setGeometry(QRect(190, 40, 113, 22));
        edtCharLinesPlus = new QLineEdit(ShockwaveParamsDlg);
        edtCharLinesPlus->setObjectName(QStringLiteral("edtCharLinesPlus"));
        edtCharLinesPlus->setGeometry(QRect(190, 100, 113, 22));
        edtCharLinesMinus = new QLineEdit(ShockwaveParamsDlg);
        edtCharLinesMinus->setObjectName(QStringLiteral("edtCharLinesMinus"));
        edtCharLinesMinus->setGeometry(QRect(190, 130, 113, 22));
        edtInternalEnergy = new QLineEdit(ShockwaveParamsDlg);
        edtInternalEnergy->setObjectName(QStringLiteral("edtInternalEnergy"));
        edtInternalEnergy->setGeometry(QRect(190, 160, 113, 22));
        edtNonDimHeatRel = new QLineEdit(ShockwaveParamsDlg);
        edtNonDimHeatRel->setObjectName(QStringLiteral("edtNonDimHeatRel"));
        edtNonDimHeatRel->setGeometry(QRect(190, 190, 113, 22));
        edtEnthalpy = new QLineEdit(ShockwaveParamsDlg);
        edtEnthalpy->setObjectName(QStringLiteral("edtEnthalpy"));
        edtEnthalpy->setGeometry(QRect(190, 220, 113, 22));
        edtCurrent = new QLineEdit(ShockwaveParamsDlg);
        edtCurrent->setObjectName(QStringLiteral("edtCurrent"));
        edtCurrent->setGeometry(QRect(190, 250, 111, 22));
        edtWidthOfDetonation = new QLineEdit(ShockwaveParamsDlg);
        edtWidthOfDetonation->setObjectName(QStringLiteral("edtWidthOfDetonation"));
        edtWidthOfDetonation->setGeometry(QRect(190, 280, 113, 22));
        edtMachNum = new QLineEdit(ShockwaveParamsDlg);
        edtMachNum->setObjectName(QStringLiteral("edtMachNum"));
        edtMachNum->setGeometry(QRect(190, 310, 113, 22));
        edtConstVolSpecificHeat = new QLineEdit(ShockwaveParamsDlg);
        edtConstVolSpecificHeat->setObjectName(QStringLiteral("edtConstVolSpecificHeat"));
        edtConstVolSpecificHeat->setGeometry(QRect(190, 70, 113, 22));
        label_23 = new QLabel(ShockwaveParamsDlg);
        label_23->setObjectName(QStringLiteral("label_23"));
        label_23->setGeometry(QRect(330, 130, 51, 16));
        label_22 = new QLabel(ShockwaveParamsDlg);
        label_22->setObjectName(QStringLiteral("label_22"));
        label_22->setGeometry(QRect(330, 100, 151, 16));
        edtPressure = new QLineEdit(ShockwaveParamsDlg);
        edtPressure->setObjectName(QStringLiteral("edtPressure"));
        edtPressure->setGeometry(QRect(190, 340, 113, 22));
        edtGasType = new QLineEdit(ShockwaveParamsDlg);
        edtGasType->setObjectName(QStringLiteral("edtGasType"));
        edtGasType->setGeometry(QRect(190, 430, 113, 22));
        edtHeatRel = new QLineEdit(ShockwaveParamsDlg);
        edtHeatRel->setObjectName(QStringLiteral("edtHeatRel"));
        edtHeatRel->setGeometry(QRect(190, 400, 113, 22));
        edtMagPress = new QLineEdit(ShockwaveParamsDlg);
        edtMagPress->setObjectName(QStringLiteral("edtMagPress"));
        edtMagPress->setGeometry(QRect(190, 370, 113, 22));
        edtTempR1 = new QLineEdit(ShockwaveParamsDlg);
        edtTempR1->setObjectName(QStringLiteral("edtTempR1"));
        edtTempR1->setGeometry(QRect(190, 520, 113, 22));
        edtEntropy = new QLineEdit(ShockwaveParamsDlg);
        edtEntropy->setObjectName(QStringLiteral("edtEntropy"));
        edtEntropy->setGeometry(QRect(190, 490, 113, 22));
        edtRadialDist = new QLineEdit(ShockwaveParamsDlg);
        edtRadialDist->setObjectName(QStringLiteral("edtRadialDist"));
        edtRadialDist->setGeometry(QRect(190, 460, 113, 22));
        edtShockDetSpeed = new QLineEdit(ShockwaveParamsDlg);
        edtShockDetSpeed->setObjectName(QStringLiteral("edtShockDetSpeed"));
        edtShockDetSpeed->setGeometry(QRect(480, 100, 113, 22));
        edtSpecificVol = new QLineEdit(ShockwaveParamsDlg);
        edtSpecificVol->setObjectName(QStringLiteral("edtSpecificVol"));
        edtSpecificVol->setGeometry(QRect(480, 70, 113, 22));
        edtVelocity = new QLineEdit(ShockwaveParamsDlg);
        edtVelocity->setObjectName(QStringLiteral("edtVelocity"));
        edtVelocity->setGeometry(QRect(480, 40, 113, 22));
        edtTime = new QLineEdit(ShockwaveParamsDlg);
        edtTime->setObjectName(QStringLiteral("edtTime"));
        edtTime->setGeometry(QRect(480, 10, 113, 22));
        edtPosition = new QLineEdit(ShockwaveParamsDlg);
        edtPosition->setObjectName(QStringLiteral("edtPosition"));
        edtPosition->setGeometry(QRect(480, 130, 113, 22));
        label_24 = new QLabel(ShockwaveParamsDlg);
        label_24->setObjectName(QStringLiteral("label_24"));
        label_24->setGeometry(QRect(10, 550, 151, 16));
        edtTempR2 = new QLineEdit(ShockwaveParamsDlg);
        edtTempR2->setObjectName(QStringLiteral("edtTempR2"));
        edtTempR2->setGeometry(QRect(190, 550, 113, 22));

        retranslateUi(ShockwaveParamsDlg);
        QObject::connect(btnsOkayCancel, SIGNAL(accepted()), ShockwaveParamsDlg, SLOT(accept()));
        QObject::connect(btnsOkayCancel, SIGNAL(rejected()), ShockwaveParamsDlg, SLOT(reject()));

        QMetaObject::connectSlotsByName(ShockwaveParamsDlg);
    } // setupUi

    void retranslateUi(QDialog *ShockwaveParamsDlg)
    {
        ShockwaveParamsDlg->setWindowTitle(QApplication::translate("ShockwaveParamsDlg", "Shock wave Parameters", 0));
        label->setText(QApplication::translate("ShockwaveParamsDlg", "Magnetic Field Strength:", 0));
        label_2->setText(QApplication::translate("ShockwaveParamsDlg", "ConstPressure/Specific Heat:", 0));
        label_3->setText(QApplication::translate("ShockwaveParamsDlg", "ConstVolume/Specific Heat:", 0));
        label_4->setText(QApplication::translate("ShockwaveParamsDlg", "Characteristic Lines+:", 0));
        label_5->setText(QApplication::translate("ShockwaveParamsDlg", "Internal Energy:", 0));
        label_6->setText(QApplication::translate("ShockwaveParamsDlg", "Characteristic Lines-:", 0));
        label_7->setText(QApplication::translate("ShockwaveParamsDlg", "Nondimensional Heat Release:", 0));
        label_8->setText(QApplication::translate("ShockwaveParamsDlg", "Enthalpy:", 0));
        label_9->setText(QApplication::translate("ShockwaveParamsDlg", "Current:", 0));
        label_10->setText(QApplication::translate("ShockwaveParamsDlg", "Width of Detonation Wave:", 0));
        label_11->setText(QApplication::translate("ShockwaveParamsDlg", "Pressure:", 0));
        label_12->setText(QApplication::translate("ShockwaveParamsDlg", "Mach Number:", 0));
        label_13->setText(QApplication::translate("ShockwaveParamsDlg", "Magnetic Pressure:", 0));
        label_14->setText(QApplication::translate("ShockwaveParamsDlg", "Heat Release:", 0));
        label_15->setText(QApplication::translate("ShockwaveParamsDlg", "Gas Type:", 0));
        label_16->setText(QApplication::translate("ShockwaveParamsDlg", "Radial Distance:", 0));
        label_17->setText(QApplication::translate("ShockwaveParamsDlg", "Entropy:", 0));
        label_18->setText(QApplication::translate("ShockwaveParamsDlg", "Region1 Temperature (K):", 0));
        label_19->setText(QApplication::translate("ShockwaveParamsDlg", "Time (seconds):", 0));
        label_20->setText(QApplication::translate("ShockwaveParamsDlg", "Specific Volume", 0));
        label_21->setText(QApplication::translate("ShockwaveParamsDlg", "Velocity (m/s)", 0));
        label_23->setText(QApplication::translate("ShockwaveParamsDlg", "Position: ", 0));
        label_22->setText(QApplication::translate("ShockwaveParamsDlg", "Shock/Detonation Speed: ", 0));
        label_24->setText(QApplication::translate("ShockwaveParamsDlg", "Region2 Temperature (K):", 0));
    } // retranslateUi

};

namespace Ui {
    class ShockwaveParamsDlg: public Ui_ShockwaveParamsDlg {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SHOCKWAVEPARAMSDLG_H
