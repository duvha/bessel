#ifndef BESSEL_H
#define BESSEL_H

#include <vector>
#include <array>
#include <cstdint>

class Bessel
{
public:
    explicit Bessel();
    ~Bessel();
    uint8_t output();
    std::vector<std::pair<double, double>> sideBands(uint8_t output);

private:
    uint8_t m_output;
    std::array<uint8_t, 100> TL_LUT;
    std::vector<std::pair<double, double>> m_sideBands;
};

#endif // BESSEL_H
