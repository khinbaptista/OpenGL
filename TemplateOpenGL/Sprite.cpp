#include "Sprite.h"

using namespace std;
using namespace glm;

Sprite::Sprite(SDL_Renderer *renderer, string filepath)
{
	SDL_Surface *surface = SDL_LoadBMP(filepath.c_str());
	if (surface == nullptr){
		cout << "Error loading BMP file: " << SDL_GetError() << endl;
		return;
	}

	sprite = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (sprite == nullptr){
		cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
		return;
	}

	source = NULL;
	destination = NULL;
}

Sprite::Sprite(SDL_Renderer *renderer, string filepath, SDL_Rect *source, SDL_Rect *destination){
	SDL_Surface *surface = SDL_LoadBMP(filepath.c_str());
	if (surface == nullptr){
		cout << "Error loading BMP file: " << SDL_GetError() << endl;
		return;
	}

	width = surface->w;
	height = surface->h;

	sprite = SDL_CreateTextureFromSurface(renderer, surface);
	SDL_FreeSurface(surface);
	if (sprite == nullptr){
		cout << "SDL_CreateTextureFromSurface Error: " << SDL_GetError() << endl;
		return;
	}

	this->source = source;
	this->destination = destination;
}

Sprite::~Sprite(){

}

// Gets the position of this sprite;
vec2 Sprite::Position(void){
	if (destination == NULL)
		return vec2(0.0f, 0.0f);
	else
		return vec2(destination->x, destination->y);
}

// Sets the position of this sprite;
void Sprite::Position(vec2 position){
	if (destination == NULL){
		cout << "This sprite has a NULL destination";
		return;
	}

	destination->x = int(position.x);
	destination->y = int(position.y);
}

// Gets the width of the whole sprite
int Sprite::Width(void){
	return width;
}

// Gets the height of the whole sprite
int Sprite::Height(void){
	return height;
}

// Gets the source rectangle of this sprite
SDL_Rect Sprite::SourceRectangle(void){
	return *source;
}

// Sets the source rectangle of this sprite
void Sprite::SourceRectangle(SDL_Rect *source){
	this->source = source;
}

// Gets the destination rectangle of this sprite
SDL_Rect Sprite::DestinationRectangle(void){
	return *destination;
}

// Sets the destination rectangle of this sprite
void Sprite::DestinationRectangle(SDL_Rect *destination){
	this->destination = destination;
}

// Renders the sprite
void Sprite::Draw(SDL_Renderer *renderer){
	SDL_RenderCopy(renderer, sprite, source, destination);

	SDL_RenderPresent(renderer);
}