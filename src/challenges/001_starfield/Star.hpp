#pragma once

#include <SDL_render.h>

class Star
{
    double m_x;
    double m_y;
    double m_z;

  public:
    Star(size_t windowWidth, size_t windowHeight);

    void update();
    void show(SDL_Renderer* renderer) const;
};
