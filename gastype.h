#ifndef GASTYPE_H
#define GASTYPE_H

#include "commondefs.h"

class GasType {
public:
    GasType() {}
    GasType(const string name, const double gasConst) : m_name(name), m_gasConst(gasConst) {}

    string Name() const { return m_name; }
    double GasConst() const { return m_gasConst; }
private:
    string m_name;
    double m_gasConst;
};

#endif // GASTYPE_H
