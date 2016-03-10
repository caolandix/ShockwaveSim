#include <math.h>
#include <stdexcept>
#include "shockwavecalculations.h"

ShockWaveCalculations::ShockWaveCalculations(const ShockwaveDataObj &obj) {
    m_ShockwaveData = obj;
}

ShockWaveCalculations::~ShockWaveCalculations() {
}

void ShockWaveCalculations::rhTemperature(double *T2_div_T1, const double gamma, const double mach) {
    if (T2_div_T1)
        *T2_div_T1 = (((1 + (gamma - 1)) / 2) * pow(mach, 2)) * ((((2 * gamma) / (gamma - 1)) * (pow(mach, 2) - 1)) /
            (pow(mach, 2) * (((2 * gamma) / (gamma - 1)) + ((gamma - 1) / 2))));
    else
        throw std::runtime_error("Null Pointer Exception: ShockWaveCalculations::rhTemperature()");
}

void ShockWaveCalculations::rhStaticPressure(double *P2_div_P1, const double gamma, const double mach) {
    if (P2_div_P1)
        *P2_div_P1 = ((2 * gamma * pow(mach, 2)) / (gamma + 1)) - ((gamma - 1) / (gamma + 1));
    else
        throw std::runtime_error("Null Pointer Exception: ShockWaveCalculations::rhStaticPressure()");
}

void ShockWaveCalculations::rhDensityVelocity(double *rho2_div_rho1, const double gamma, const double mach) {
    if (rho2_div_rho1)
        *rho2_div_rho1 = (((gamma + 1) * pow(mach, 2)) / ((gamma - 1) * pow(mach, 2) + 2));
    else
        throw std::runtime_error("Null Pointer Exception: ShockWaveCalculations::rhDensityVelocity()");
}
