#include "Star.hpp"
#include <SDL.h>
#include <SDL_render.h>
#include <SDL_video.h>
#include <vector>

constexpr size_t WINDOW_WIDTH = 800;
constexpr size_t WINDOW_HEIGHT = 600;

int main(int /*argc*/, char** /*argv*/)
{
    SDL_Init(SDL_INIT_VIDEO);
    SDL_Window* window = SDL_CreateWindow("Starfield", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH,
                                          WINDOW_HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI);
    Renderer renderer{window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC};

    std::vector<Star> stars;
    stars.reserve(500);
    for (size_t i = 0; i < 500; ++i)
    {
        stars.emplace_back(WINDOW_WIDTH, WINDOW_HEIGHT);
    }

    bool quit = false;
    while (!quit)
    {
        SDL_Event event;
        while (SDL_PollEvent(&event) != 0)
        {
            switch (event.type)
            {
            case SDL_QUIT:
                quit = true;
                break;
            default:
                break;
            }
        }

        renderer.loadIdentity();
        renderer.setDrawColor({0, 0, 0, 255});
        renderer.clear();

        renderer.translate({WINDOW_WIDTH / 2, WINDOW_HEIGHT / 2});
        for (auto& star : stars)
        {
            star.update();
            star.show(&renderer);
        }

        renderer.present();
    }

    SDL_DestroyWindow(window);
    SDL_Quit();
    return 0;
}
