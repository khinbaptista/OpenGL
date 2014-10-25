#pragma once

#include <glm/glm.hpp>
#include <SDL.h>
#include "Sprite.h"

class Font2D
{
private:
	glm::vec2 dimensions;
	int charactersPerLine;
	int lineCount;
	Sprite *sprite;

public:
	Font2D(void);
	Font2D(Sprite *sprite, int charactersPerLine, int lineCount, int characterWidth = -1, int characterHeight = -1);
	~Font2D();

	void Write(SDL_Renderer *renderer, glm::vec2 position, const char* text, int layer = 2);
	SDL_Rect CharacterBound(char character);
	int MeasureString(const char* text);
};