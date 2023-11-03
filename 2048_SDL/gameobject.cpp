#include <iostream>
#include <SDL.h>

#include "gameobject.h"
#include "window.h"

using namespace std;

/***
* CONSTRUCTOR
*   GameObject
*       _x          -> position in x
*       _y          -> position in y
*       _height     -> height of the object
*       _widht      -> width of the object
*       pRenderer   -> canva of the window
* 
* load variables and all textures
*/
GameObject::GameObject(int _x, int _y, int _height, int _width, SDL_Renderer* pRenderer) {
	x = _x;
	y = _y; 
	height = _height;
	width = _width;

    pSurface = NULL;
    pTexture = NULL;

    LoadAllTexture(pRenderer);
}


/***
* METHOD
*   loadAllTexture
*       pRenderer       -> canva of the window
*/
void GameObject::LoadAllTexture(SDL_Renderer* pRenderer)
{
    for (int i = 0; i < 9; i++) {
        albums.push_back(LoadImg(pRenderer, paths[i]));
    }
}

/***
* METHOD
*   loadImg
*       pRenderer       -> canva of the window
*       path            -> path of the picture on the folfer
* 
* load img on surface and create a texture ( less heavy )
*/
SDL_Texture* GameObject::LoadImg(SDL_Renderer* pRenderer, const char* path)
{
    //On charge une Image (SDL_Surface)
    pSurface = SDL_LoadBMP(path);
    if (pSurface == NULL)
    {
        std::cout << "Error SDL_LoadBMP :" << SDL_GetError();
        exit(1);
    }
    pTexture = SDL_CreateTextureFromSurface(pRenderer, pSurface);
    if (pTexture == NULL)
    {
        std::cout << "Error SDL_CreateTextureFromSurface :" << SDL_GetError();
        exit(1);
    }
    SDL_FreeSurface(pSurface);

    return pTexture;
}

/***
* METHOD
*   drawImg
*       pRenderer       -> canva of the window
*       _pTexture       -> texture of the picture
*/
void GameObject::DrawImg(SDL_Renderer* pRenderer, SDL_Texture* _pTexture)
{
    SDL_Rect oPosition;
    oPosition.x = x;
    oPosition.y = y;

    SDL_QueryTexture(_pTexture, NULL, NULL, &oPosition.w, &oPosition.h);

    SDL_RenderCopy(pRenderer, _pTexture, NULL, &oPosition);
}

/***
* DESTRUCTOR
*   GameObject
*/
GameObject::~GameObject()
{
    if (pTexture != NULL)
        SDL_DestroyTexture(pTexture);
}