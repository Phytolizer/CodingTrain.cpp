#include "Star.hpp"
#include <SDL2_gfxPrimitives.h>
#include <SDL_render.h>
#include <helpers/Renderer.hpp>
#include <helpers/math.hpp>
#include <helpers/random.hpp>

Star::Star(size_t windowWidth, size_t windowHeight)
    : m_x(Random::getDouble(-static_cast<double>(windowWidth), static_cast<double>(windowWidth))),
      m_y(Random::getDouble(-static_cast<double>(windowHeight), static_cast<double>(windowHeight))),
      m_z(Random::getDouble(0, static_cast<double>(windowWidth))), m_windowWidth(windowWidth),
      m_windowHeight(windowHeight)
{
}

void Star::update()
{
    m_z -= 10;
    if (m_z < 1)
    {
        m_x = Random::getDouble(-static_cast<double>(m_windowWidth), static_cast<double>(m_windowWidth));
        m_y = Random::getDouble(-static_cast<double>(m_windowHeight), static_cast<double>(m_windowHeight));
        m_z = Random::getDouble(0, static_cast<double>(m_windowWidth));
    }
}

void Star::show(Renderer* renderer) const
{
    double sx = Math::map(m_x / m_z, 0, 1, 0, static_cast<double>(m_windowWidth));
    double sy = Math::map(m_y / m_z, 0, 1, 0, static_cast<double>(m_windowWidth));
    double r = Math::map(m_z, 0, static_cast<double>(m_windowWidth), 8, 0);

    renderer->drawFilledCircle({sx, sy}, r, {255, 255, 255, 255});
}
