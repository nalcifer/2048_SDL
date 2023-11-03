#include <vector>
#include <SDL.h>

class GameObject
{
private :
	int x, y, height, width;


public :
	const char* paths[9] = { "Free Box.bmp","Taylor Swift Debut.bmp", "Speak Now.bmp", "Red.bmp", "1989.bmp", "Reputation.bmp", "Lover.bmp", "Evermore.bmp", "Midnights.bmp"};
	std::vector<SDL_Texture*> albums;
	 

	SDL_Texture* pTexture = NULL;
	SDL_Surface* pSurface = NULL;

	GameObject(int _x, int _y, int _height, int _width, SDL_Renderer* pRenderer);
	~GameObject();

	void LoadAllTexture(SDL_Renderer* pRenderer);
	SDL_Texture* LoadImg(SDL_Renderer* pRenderer, const char* path);
	void DrawImg(SDL_Renderer* pRenderer, SDL_Texture* _pTexture);
};