#include <QtWidgets>
#include "shockwaveparams.h"

ShockwaveParams::ShockwaveParams(QWidget *pParent) : QDialog(pParent), m_pUI(new Ui::ShockwaveParamsDlg) {
    m_pUI -> setupUi(this);
}

ShockwaveParams::~ShockwaveParams() {
    delete m_pUI;
}
