#pragma once

#include <limits>
#include <random>

namespace Random
{

size_t getSize(size_t low = 0, size_t high = std::numeric_limits<size_t>::max());
int getInt(int low = std::numeric_limits<int>::min(), int high = std::numeric_limits<int>::max());
double getDouble(double low = 0, double high = 1);

} // namespace Random
