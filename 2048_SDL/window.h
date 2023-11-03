#include <SDL.h>

class Window
{
public :
	SDL_Surface* pWinSurface = NULL;
	SDL_Window* pWindow = NULL;
	SDL_Renderer* pRenderer = NULL;

	Window();
	void Update();
	~Window();

};
