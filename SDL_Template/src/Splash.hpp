#pragma once
#include "Common.hpp"

class Splash final {

private:
    SDL_Renderer* renderer;
    SDL_Texture* logoTexture;

    short width = 0;
    short height = 0;

    void load();
    void loop();
    void render();
    void input();
    void unload();

public:
    Splash(SDL_Renderer* renderer, short width, short height);
    ~Splash();
};