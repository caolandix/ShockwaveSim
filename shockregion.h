#ifndef SHOCKREGION_H
#define SHOCKREGION_H


class ShockRegion {
public:
    ShockRegion();
    ShockRegion(const ShockRegion &);

    // copy overload
    ShockRegion &operator=(const ShockRegion &);
    bool operator==(const ShockRegion &);

    double Temperature() const { return m_Temperature; }
    void Temperature(const float val) { m_Temperature = val; }
private:
    double m_Temperature;
};

#endif // SHOCKREGION_H
