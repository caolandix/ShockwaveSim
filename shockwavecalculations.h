#ifndef SHOCKWAVECALCULATIONS_H
#define SHOCKWAVECALCULATIONS_H

#include "shockwavedataobj.h"

class ShockWaveCalculations {
public:
    ShockWaveCalculations(const ShockwaveDataObj &);
    ~ShockWaveCalculations();


    double rhTemperature();
    double rhStaticPressure();
    double rhDensityVelocity();

    double speedOfSound(const double, const double, const double);
    double mach(const double, const double);

private:
    ShockwaveDataObj m_ShockwaveData;
};

#endif // SHOCKWAVECALCULATIONS_H
