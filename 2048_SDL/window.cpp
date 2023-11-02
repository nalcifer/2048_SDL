#include <iostream>
#include <SDL.h>

#include "window.h"

using namespace std;


/***
* CONSTRUCTOR
* 
* Creation Window and Renderer
*/
Window::Window() {

	pWinSurface = NULL;
	pWindow = NULL;
	pRenderer = NULL;

	// Init SDL
	if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
		cout << "Error initializing SDL: " << SDL_GetError() << endl;
		exit(1);
	}
	
	// Construction window
	pWindow = SDL_CreateWindow("2048 (Taylor's Version)", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, 1280, 720, SDL_WINDOW_SHOWN);
	if (pWindow == NULL){
		std::cout << "Erreur SDL_CreateWindow :" << SDL_GetError();
		exit(1);
	}

	// Construction renderer
	pRenderer = SDL_CreateRenderer(pWindow, -1, SDL_RENDERER_ACCELERATED);
	if (pRenderer == nullptr) {
		std::cerr << "Échec de création du rendu : " << SDL_GetError() << std::endl;
		exit(1);
	}

	
	pWinSurface = SDL_GetWindowSurface(pWindow);

	SDL_FillRect(pWinSurface, NULL, SDL_MapRGB(pWinSurface->format, 100, 25, 200));

	SDL_UpdateWindowSurface(pWindow);

}


/***
* METHOD 
* 
* To update the canva
*/
void Window::Update() {

	SDL_RenderPresent(pRenderer);

}



/***
* DESTRUCTOR
*/
Window::~Window() {
	SDL_DestroyRenderer(pRenderer);
	SDL_DestroyWindow(pWindow);

	SDL_Quit();
}