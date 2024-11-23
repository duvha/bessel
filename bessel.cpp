#include <cmath>

#include "bessel.h"

Bessel::Bessel()
{
    m_output = 0;

    TL_LUT = { 127, 122, 118, 114, 110, 107, 104, 102, 100, 98, 96, 94, 92, 90, 88, 86, 85, 84, 82 };
    for (uint8_t i = 19; i < 100; i++) TL_LUT[i] = 99 - i;
}

uint8_t Bessel::output()
{
    return m_output;
}

std::vector<std::pair<double, double>> Bessel::sideBands(uint8_t output)
{
    m_output = output;

    uint8_t totalLevel = TL_LUT[output];
    double modulationIndex = 8.0*M_PI * pow(2, (-totalLevel/8.0));

    m_sideBands.clear();
	
	// following the rule of thumb given in the Chowning FM book
    int numSideBands = static_cast<int>(modulationIndex) + 2;
    for (int i = 0; i < numSideBands; i++)
    {
        m_sideBands.push_back(std::pair<double, double>(i, jn(i, modulationIndex)));
    }

    return m_sideBands;
}

Bessel::~Bessel()
{
}
