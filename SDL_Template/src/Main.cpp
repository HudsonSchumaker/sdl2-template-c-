#include "Common.hpp"
#include "Splash.hpp"

SDL_Window* window;
SDL_Renderer* renderer;

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
    int data = 10;
    SDL_Thread* thread = SDL_CreateThread(threadFunction, "runner", (void*)data);

    window = SDL_CreateWindow(
        Common::TITLE, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED,
        Common::WIDTH,
        Common::HEIGHT,
        SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL
    );

    SDL_Surface* iconSurface = IMG_Load("data/joypad.png");
    SDL_SetWindowIcon(window, iconSurface);

    renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);
    Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 256);
}

void quit() {
    SDL_Quit();
    TTF_Quit();
}

int main(int argc, char* argv[]) {
    setUp();
    
    Splash* splash = new Splash(renderer);
    delete splash;
    
    quit();
    return 0;
}