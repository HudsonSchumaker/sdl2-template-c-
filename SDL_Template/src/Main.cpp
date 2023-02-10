#include "Common.hpp"
#include "Splash.hpp"

SDL_Window* window;
SDL_Renderer* renderer;
unsigned short WIDTH = 0;
unsigned short HEIGHT = 0;

int threadFunction(void* data) {
    for (int i = 0; i < 90000000; i++) {
        std::cout << i << '\n' << std::endl;
    }
    return 0;
}

void setUp() {
    HWND windowHandle = GetConsoleWindow();
    ShowWindow(windowHandle, SW_HIDE);

    SDL_Init(SDL_INIT_EVERYTHING);
    TTF_Init();
    SDLNet_Init();
    int data = 10;
    SDL_Thread* thread = SDL_CreateThread(threadFunction, "runner", (void*)data);

    SDL_DisplayMode displayMode;
    SDL_GetCurrentDisplayMode(0, &displayMode);
    WIDTH = displayMode.w;
    HEIGHT = displayMode.h;

    window = SDL_CreateWindow(
        Common::TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        WIDTH,
        HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    SDL_Surface* iconSurface = IMG_Load("data/joypad.png");
    SDL_SetWindowIcon(window, iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 256);
}

void quit() {
    SDLNet_Quit();
    TTF_Quit();
    Mix_Quit();
    IMG_Quit();
    SDL_Quit();
}

int main(int argc, char* argv[]) {
    setUp();
    
    Splash* splash = new Splash(renderer, WIDTH, HEIGHT);
    delete splash;
    
    quit();
    return 0;
}
