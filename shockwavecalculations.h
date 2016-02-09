#ifndef SHOCKWAVECALCULATIONS_H
#define SHOCKWAVECALCULATIONS_H

#include "shockwavedataobj.h"

class ShockWaveCalculations {
public:
    ShockWaveCalculations();
    ~ShockWaveCalculations();

private:
    ShockwaveDataObj *m_pShockwave;
};

#endif // SHOCKWAVECALCULATIONS_H
