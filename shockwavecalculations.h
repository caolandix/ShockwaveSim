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

private:
    ShockwaveDataObj m_ShockwaveData;
};

#endif // SHOCKWAVECALCULATIONS_H
