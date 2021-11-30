#include "helpers/math.hpp"

double Math::map(double x, double inMin, double inMax, double outMin, double outMax)
{
    return (x - inMin) * (outMax - outMin) / (inMax - inMin) + outMin;
}
