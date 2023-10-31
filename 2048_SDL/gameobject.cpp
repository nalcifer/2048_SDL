#include <iostream>
#include <SDL.h>
#include "gameobject.h"
#include "window.h"

using namespace std;

GameObject::GameObject(int x, int y, int height, int width) {

}

void GameObject::draw(SDL_Renderer* renderer) 
{
	SDL_SetRenderDrawColor(renderer, 255, 0, 0, 255);
	SDL_Rect rect = { 100, 100, 100, 100 };
	SDL_RenderDrawRect(renderer, &rect);
}

	//SDL_RenderPresent(renderer);