#include <SDL.h>

class Window
{
public :
	SDL_Surface* pWinSurface = NULL;
	SDL_Window* pWindow = NULL;
	SDL_Renderer* pRenderer = NULL;

	int windowH;
	int windowW;

	Window();
	void Update();
	~Window();

};
