#pragma once

#include <SDL.h>
#include <string>
#include <glm/glm.hpp>
#include <iostream>

using namespace std;

class Sprite
{
private:
	SDL_Texture *sprite;
	int width;
	int height;

	SDL_Rect *source;
	SDL_Rect *destination;

public:
	Sprite(SDL_Renderer *renderer, string filepath);
	Sprite(SDL_Renderer *renderer, string filepath, SDL_Rect *source, SDL_Rect *destination);
	~Sprite();

	glm::vec2 Position(void);
	void Position(glm::vec2 position);

	int Width(void);
	int Height(void);

	SDL_Rect SourceRectangle(void);
	void SourceRectangle(SDL_Rect *source);

	SDL_Rect DestinationRectangle(void);
	void DestinationRectangle(SDL_Rect *destination);

	void Draw(SDL_Renderer *renderer);
};
