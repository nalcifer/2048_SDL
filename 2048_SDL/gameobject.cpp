#include <iostream>
#include <SDL.h>
#include "gameobject.h"
#include "window.h"

using namespace std;

GameObject::GameObject(int _x, int _y, int _height, int _width, SDL_Renderer* pRenderer) {
	x = _x;
	y = _y; 
	height = _height;
	width = _width;

    pSurface = NULL;
    pTexture = NULL;

    LoadAllTexture(pRenderer);
}

//void GameObject::draw(SDL_Renderer* pRenderer) 
//{
//	SDL_SetRenderDrawColor(pRenderer, 255, 0, 0, 255);
//	SDL_Rect rect = { x, y, height, width };
//	SDL_RenderDrawRect(pRenderer, &rect);
//}



void GameObject::LoadAllTexture(SDL_Renderer* pRenderer)
{
    for (int i = 0; i < 9; i++) {
        albums.push_back(LoadImg(pRenderer, paths[i]));
    }
}

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

void GameObject::DrawImg(SDL_Renderer* pRenderer, SDL_Texture* _pTexture)
{
    SDL_Rect oPosition;
    oPosition.x = x;
    oPosition.y = y;

    SDL_QueryTexture(_pTexture, NULL, NULL, &oPosition.w, &oPosition.h);

    SDL_RenderCopy(pRenderer, _pTexture, NULL, &oPosition);
}

GameObject::~GameObject()
{
    if (pTexture != NULL)
        SDL_DestroyTexture(pTexture);
}