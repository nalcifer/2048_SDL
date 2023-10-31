#include <iostream>
#include <SDL.h>

#include "window.h"

using namespace std;

Window::Window() {

	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;

	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		system("pause");
	}
	
	window = SDL_CreateWindow("2048 (Taylor's Version)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);

	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	if (renderer == nullptr) {
			std::cerr << "Échec de création du rendu : " << SDL_GetError() << std::endl;
	}

	
	winSurface = SDL_GetWindowSurface(window);

	SDL_FillRect(winSurface, NULL, SDL_MapRGB(winSurface->format, 100, 25, 200));

	SDL_UpdateWindowSurface(window);

	system("pause");

	
}

Window::~Window() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	SDL_Quit();
}