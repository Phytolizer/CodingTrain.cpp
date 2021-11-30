#include "helpers/random.hpp"

namespace
{
std::random_device rd;                // NOLINT
std::default_random_engine eng(rd()); // NOLINT
} // namespace

size_t Random::getSize(size_t low, size_t high)
{
    std::uniform_int_distribution<size_t> dist(low, high);
    return dist(eng);
}

int Random::getInt(int low, int high)
{
    std::uniform_int_distribution<int> dist(low, high);
    return dist(eng);
}

double Random::getDouble(double low, double high)
{
    std::uniform_real_distribution<double> dist(low, high);
    return dist(eng);
}
