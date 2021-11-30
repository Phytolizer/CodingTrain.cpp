#include "Star.hpp"
#include <SDL2_gfxPrimitives.h>
#include <SDL_render.h>
#include <helpers/random.hpp>

Star::Star(size_t windowWidth, size_t windowHeight)
    : m_x(Random::getDouble(-static_cast<int>(windowWidth), static_cast<int>(windowWidth))),
      m_y(Random::getDouble(-static_cast<int>(windowHeight), static_cast<int>(windowHeight))),
      m_z(Random::getDouble(0, static_cast<int>(windowWidth)))
{
}

void Star::update()
{
}

void Star::show(SDL_Renderer* renderer) const
{
    double sx = m_x / m_z;
    filledCircleRGBA(renderer, static_cast<Sint16>(m_x), static_cast<Sint16>(m_y), 4, 255, 255, 255, 255);
}
