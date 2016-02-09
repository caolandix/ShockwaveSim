#include "shockwavecalculations.h"

ShockWaveCalculations::ShockWaveCalculations() {
    m_pShockwave = new ShockwaveDataObj();
}

ShockWaveCalculations::~ShockWaveCalculations() {
    delete m_pShockwave;
}

