#include "shockregion.h"

ShockRegion::ShockRegion() {
}

ShockRegion::ShockRegion(const ShockRegion &obj) {
    m_Temperature = obj.Temperature();
}

// copy overload
ShockRegion &ShockRegion::operator=(const ShockRegion &obj) {
    if (this != &obj) {
        m_Temperature = obj.Temperature();
    }
    return *this;
}

// other overloads
bool ShockRegion::operator==(const ShockRegion &obj) {
    if (m_Temperature != obj.Temperature())
        return false;
    return true;
}
