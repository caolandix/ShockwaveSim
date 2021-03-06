#include "shockwavedataobj.h"

ShockwaveDataObj::ShockwaveDataObj(const double idealGasConst, const double gamma) {
    m_idealGasConst = idealGasConst;
    m_Gamma = gamma;
    m_soundSpeed = 0.0;
    m_magFieldStr = 0.0;
    m_constPressSpecificHeat = 0.0;
    m_constVolSpecificHeat = 0.0;
    m_charisticLinesPlus = 0.0;
    m_charisticLinesMinus = 0.0;
    m_internalEnergy = 0.0;
    m_nonDimHeatRelParam = 0.0;
    m_Enthalpy = 0.0;
    m_Current = 0.0;
    m_ReimannInvariantPlus = 0.0;
    m_ReimannInvariantMinus = 0.0;
    m_widthDetonationWaveSys = 0.0;
    m_Mach = 0.0;
    m_Pressure = 0.0;
    m_magPressureParam = 0.0;
    m_heatRelParam = 0.0;
    m_radialDist = 0.0;
    m_Entropy = 0.0;
    m_TempRegion1 = 0.0;
    m_TempRegion2 = 0.0;
    m_Time = 0.0;
    m_Velocity = 0.0;
    m_specificVol = 0.0;
    m_ShockDetSpeed = 0.0;
    m_Position = 0.0;
    m_Alpha = 0.0;
    m_Beta = 0.0;
    m_Mu0 = 0.0;
    m_Rho = 0.0;
    m_Sigma = 0.0;

    // if we do not have an XML file to feed the various gas types into the app then feed the basic ones
    if (m_GasTypes.size() == 0) {
        m_GasTypes.push_back(GasType("Air", 1.4));
    }
}
