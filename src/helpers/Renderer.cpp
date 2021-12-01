#include "helpers/Renderer.hpp"
#include <SDL2_gfxPrimitives.h>
#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

Renderer::Renderer(SDL_Window* window, int displayIndex, Uint32 flags)
    : m_transform{1}, m_renderer{SDL_CreateRenderer(window, displayIndex, flags)}
{
}

Renderer::~Renderer()
{
    SDL_DestroyRenderer(m_renderer);
}

void Renderer::translate(glm::vec2 translation)
{
    m_transform = glm::translate(m_transform, glm::vec3{translation, 0});
}

void Renderer::drawFilledCircle(glm::vec2 center, double radius, SDL_Color color)
{
    glm::vec2 transformedCenter = m_transform * glm::vec4{center, 0, 1};
    filledCircleRGBA(m_renderer, static_cast<Sint16>(transformedCenter.x), static_cast<Sint16>(transformedCenter.y),
                     static_cast<Sint16>(radius), color.r, color.g, color.b, color.a);
}

void Renderer::setDrawColor(SDL_Color color)
{
    SDL_SetRenderDrawColor(m_renderer, color.r, color.g, color.b, color.a);
}

void Renderer::clear()
{
    SDL_RenderClear(m_renderer);
}

void Renderer::present()
{
    SDL_RenderPresent(m_renderer);
}

void Renderer::loadIdentity()
{
    m_transform = glm::mat4{1};
}
