#include "Font2D.h"

using namespace glm;

Font2D::Font2D(){
}

Font2D::Font2D(Sprite *sprite, int charactersPerLine,
				int lineCount, int characterWidth, int characterHeight){
	if (characterWidth != -1 && characterHeight != -1)
		dimensions = vec2(characterWidth, characterHeight);
	else{
		int charWidth, charHeight;

		charWidth = sprite->Width() / charactersPerLine;
		charHeight = sprite->Height() / lineCount;

		dimensions = vec2(charWidth, charHeight);
	}

	this->charactersPerLine = charactersPerLine;
	this->lineCount = lineCount;

	this->sprite = sprite;
}

Font2D::~Font2D(){
}

// Writes the given text in the given position.
void Font2D::Write(SDL_Renderer *renderer, vec2 position, const char* text, int layer){
	int counter = 0;
	while (text[counter] != '\0'){
		sprite->SourceRectangle(&CharacterBound(text[counter]));

		SDL_Rect *rect = new SDL_Rect();
		rect->x = int(position.x + counter * dimensions.x);
		rect->y = int(position.y);
		rect->w = int(dimensions.x);
		rect->h = int(dimensions.y);

		sprite->DestinationRectangle(rect);
		sprite->Draw(renderer);

		counter++;
	}
}

// Gets the rectangle that evelops the given character within the loaded sprite
SDL_Rect Font2D::CharacterBound(char character){
	SDL_Rect rect = *new SDL_Rect();

	rect.x = (character % charactersPerLine) * int(dimensions.x);
	rect.y = (character / charactersPerLine) * int(dimensions.y);

	return rect;
}

// Gets the size of the string in pixels using the given dimensions
int Font2D::MeasureString(const char* text){
	int size = 0;

	int i = 0;
	while (text[i] != '\0'){
		size += int(dimensions.x);
		i++;
	}

	return size;
}