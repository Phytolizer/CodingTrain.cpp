#pragma once

#include <SDL_pixels.h>
#include <SDL_render.h>
#include <glm/mat4x4.hpp>

class Renderer
{
    glm::mat4 m_transform;
    SDL_Renderer* m_renderer;

  public:
    explicit Renderer(SDL_Window* window, int displayIndex, Uint32 flags);
    Renderer(const Renderer&) = delete;
    Renderer& operator=(const Renderer&) = delete;
    Renderer(Renderer&&) = delete;
    Renderer& operator=(Renderer&&) = delete;
    ~Renderer();

    void loadIdentity();
    void translate(glm::vec2 translation);

    void setDrawColor(SDL_Color color);
    void clear();
    void present();
    void drawFilledCircle(glm::vec2 center, double radius, SDL_Color color);
};
