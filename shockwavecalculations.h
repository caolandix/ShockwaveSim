#ifndef SHOCKWAVECALCULATIONS_H
#define SHOCKWAVECALCULATIONS_H

#include "shockwavedataobj.h"

class ShockWaveCalculations {
public:
    ShockWaveCalculations(const ShockwaveDataObj &);
    ~ShockWaveCalculations();

    void rhTemperature(double *, const double, const double);
    void rhStaticPressure(double *, const double, const double);
    void rhDensityVelocity(double *, const double, const double);

private:
    ShockwaveDataObj m_ShockwaveData;
};

#endif // SHOCKWAVECALCULATIONS_H
