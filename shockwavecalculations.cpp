#include <math.h>
#include <stdexcept>
#include "shockwavecalculations.h"

ShockWaveCalculations::ShockWaveCalculations(const ShockwaveDataObj &obj) {
    m_ShockwaveData = obj;
}

ShockWaveCalculations::~ShockWaveCalculations() {
}

//double ShockWaveCalculations::

double ShockWaveCalculations::rhTemperature() {
    return (((1 + (m_ShockwaveData.gamma() - 1)) / 2) * pow(m_ShockwaveData.M(), 2)) * ((((2 * m_ShockwaveData.gamma()) / (m_ShockwaveData.gamma() - 1)) * (pow(m_ShockwaveData.M(), 2) - 1)) /
            (pow(m_ShockwaveData.M(), 2) * (((2 * m_ShockwaveData.gamma()) / (m_ShockwaveData.gamma() - 1)) + ((m_ShockwaveData.gamma() - 1) / 2))));
}

double ShockWaveCalculations::rhStaticPressure() {
    return ((2 * m_ShockwaveData.gamma() * pow(m_ShockwaveData.M(), 2)) / (m_ShockwaveData.gamma() + 1)) - ((m_ShockwaveData.gamma() - 1) / (m_ShockwaveData.gamma() + 1));
}

double ShockWaveCalculations::rhDensityVelocity() {
    return (((m_ShockwaveData.gamma() + 1) * pow(m_ShockwaveData.M(), 2)) / ((m_ShockwaveData.gamma() - 1) * pow(m_ShockwaveData.M(), 2) + 2));
}

double ShockWaveCalculations::speedOfSound(const double gamma, const double gasConst, const double temperature) {
    return sqrt(gamma * gasConst * (273.15 + temperature));
}

double ShockWaveCalculations::mach(const double velocity, const double currSpeedOfSound) {
    return (currSpeedOfSound != 0.0) ? velocity / currSpeedOfSound : 0.0;
}
