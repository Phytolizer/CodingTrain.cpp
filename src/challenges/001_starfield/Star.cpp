#include "Star.hpp"
#include <SDL2_gfxPrimitives.h>
#include <SDL_render.h>
#include <helpers/Renderer.hpp>
#include <helpers/math.hpp>
#include <helpers/random.hpp>

Star::Star(size_t windowWidth, size_t windowHeight)
    : m_x(Random::getDouble(-static_cast<int>(windowWidth), static_cast<int>(windowWidth))),
      m_y(Random::getDouble(-static_cast<int>(windowHeight), static_cast<int>(windowHeight))),
      m_z(Random::getDouble(0, static_cast<int>(windowWidth))), m_windowWidth(windowWidth), m_windowHeight(windowHeight)
{
}

void Star::update()
{
    --m_z;
}

void Star::show(Renderer* renderer) const
{
    double sx = Math::map(m_x / m_z, 0, 1, 0, static_cast<double>(m_windowWidth));
    double sy = Math::map(m_y / m_z, 0, 1, 0, static_cast<double>(m_windowWidth));

    renderer->drawFilledCircle({sx, sy}, 4, {255, 255, 255, 255});
}
