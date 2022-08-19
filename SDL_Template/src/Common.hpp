#pragma once

#include <math.h>
#include <vector>
#include <stdlib.h>
#include <Windows.h>
#include <string>
#include <iostream>

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include <SDL_mixer.h>
#include <SDL_thread.h>

class Common final {

public:
    inline static const char TITLE[] = "- SDL Template -";

    constexpr static float FPS = 60.0f;
    constexpr static float MILLISECS_PER_FRAME = 1000.0f / FPS;
    static const unsigned short WIDTH = 800;
    static const unsigned short H_WIDTH = WIDTH / 2;
    static const unsigned short HEIGHT = 600;
    static const unsigned short H_HEIGHT = HEIGHT / 2;
    constexpr static float PI = 3.1415f;
};
