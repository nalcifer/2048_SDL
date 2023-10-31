#include <SDL.h>

class Window
{

public :
	SDL_Surface* winSurface = NULL;
	SDL_Window* window = NULL;
	SDL_Renderer* renderer = NULL;
	Window();
	~Window();

};
