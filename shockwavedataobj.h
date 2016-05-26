#ifndef SHOCKWAVEDATAOBJ_H
#define SHOCKWAVEDATAOBJ_H


// This class wraps all of the calculations used in the modelling of the Shockwave propagation. The variables and constants
// come fromt he paper called Modeling the Propagation of a Shock Wave Through a Glow Discharge by Johnathan Poggie
// AIAA Journal -- Vol 38, No. 8, August 2000

class ShockwaveDataObj {
public:
    ShockwaveDataObj(const double idealGasConst = 208.13, const double gamma = 1.67);

    void a(const double val) { m_soundSpeed = val; }
    void B(const double val) { m_magFieldStr = val; }
    void Cp(const double val) { m_constPressSpecificHeat = val; }
    void Cv(const double val) { m_constVolSpecificHeat = val; }
    void Cplus(const double val) { m_charisticLinesPlus = val; }
    void Cminus(const double val) { m_charisticLinesMinus = val; }
    void e(const double val) { m_internalEnergy = val; }
    void H(const double val) { m_nonDimHeatRelParam = val; }
    void h(const double val) { m_Enthalpy = val; }
    void I(const double val) { m_Current = val; }
    void L(const double val) { m_widthDetonationWaveSys = val; }
    void M(const double val) { m_Mach = val; }
    void p(const double val) { m_Pressure = val; }
    void Q(const double val) { m_magPressureParam = val; }
    void q(const double val) { m_heatRelParam = val; }
    void R(const double val) { m_idealGasConst = val; }
    void r(const double val) { m_radialDist = val; }
    void s(const double val) { m_Entropy = val; }
    void T1(const double val) { m_TempRegion1 = val; }
    void T2(const double val) { m_TempRegion2 = val; }
    void t(const double val) { m_Time = val; }
    void u(const double val) { m_Velocity = val; }
    void v(const double val) { m_specificVol = val; }
    void W(const double val) { m_ShockDetSpeed = val; }
    void x(const double val) { m_Position = val; }
    void gamma(const double val) { m_Gamma = val; }
    void mu0(const double val) { m_Mu0 = val; }
    void rho(const double val) { m_Rho = val; }
    void sigma(const double val) { m_Sigma = val; }


    double a() const { return m_soundSpeed; }
    double B() const { return m_magFieldStr; }
    double Cp() const { return m_constPressSpecificHeat; }
    double Cv() const { return m_constVolSpecificHeat; }
    double Cplus() const { return m_charisticLinesPlus; }
    double Cminus() const { return m_charisticLinesMinus; }
    double e() const { return m_internalEnergy; }
    double H() const { return m_nonDimHeatRelParam; }
    double h() const { return m_Enthalpy; }
    double I() const { return m_Current; }
    double Jplus() { return m_ReimannInvariantPlus = (u() + 2 * a()) / (gamma() - 1); }
    double Jminus() { return m_ReimannInvariantMinus = (u() - 2 * a()) / (gamma() - 1); }
    double L() const { return m_widthDetonationWaveSys; }
    double M() const { return m_Mach; }
    double p() const { return m_Pressure; }
    double Q() const { return m_magPressureParam; }
    double q() const { return m_heatRelParam; }
    double R() const { return m_idealGasConst; }
    double r() const { return m_radialDist; }
    double s() const { return m_Entropy; }
    double T1() const { return m_TempRegion1; }
    double T2() const { return m_TempRegion2; }
    double t() const { return m_Time; }
    double u() const { return m_Velocity; }
    double v() const { return m_specificVol; }
    double W() const { return m_ShockDetSpeed; }
    double x() const { return m_Position; }
    double alpha() { return m_Alpha = (gamma() + 1) / (gamma() - 1); }
    double beta() { return m_Beta = (gamma() - 1) / (2 * gamma()); }
    double gamma() const { return m_Gamma; }
    double mu0() const { return m_Mu0; }
    double rho() const { return m_Rho; }
    double sigma() const { return m_Sigma; }

private:
    double m_soundSpeed;                    // a
    double m_magFieldStr;                   // B
    double m_constPressSpecificHeat;        // Cp
    double m_constVolSpecificHeat;          // Cv
    double m_charisticLinesPlus;            // Characteristic Lines +
    double m_charisticLinesMinus;           // Characteristic Lines -
    double m_internalEnergy;                // e
    double m_nonDimHeatRelParam;            // H: nondimensional heat-release parameter
    double m_Enthalpy;                      // h
    double m_Current;                       // I
    double m_ReimannInvariantPlus;          // [u + 2*a / (gamma - 1)]: J+
    double m_ReimannInvariantMinus;         // [u - 2*a / (gamma - 1)]: J-
    double m_widthDetonationWaveSys;        // L
    double m_Mach;                          // M
    double m_Pressure;                      // P
    double m_magPressureParam;              // Q
    double m_heatRelParam;                  // q
    double m_idealGasConst;                 // R: 208.13 m^2/s^2/K for argon
    double m_radialDist;                    // r
    double m_Entropy;                       // S
    double m_TempRegion1;                   // T1
    double m_TempRegion2;                   // T2
    double m_Time;                          // t
    double m_Velocity;                      // u
    double m_specificVol;                   // v
    double m_ShockDetSpeed;                 // W: Shock or detonation speed
    double m_Position;                      // x
    double m_Alpha;                         // (gamma + 1) / (gamma - 1)
    double m_Beta;                          // (gamma - 1) / 2 * gamma
    double m_Gamma;                         // Adiabatic exponent (1.67 for Argon)
    double m_Mu0;                           // Mu0: permeability of free space (4 * pi * 10^-7)
    double m_Rho;                           // density
    double m_Sigma;                         // Electrical Conductivity
};

#endif // SHOCKWAVEDATAOBJ_H
