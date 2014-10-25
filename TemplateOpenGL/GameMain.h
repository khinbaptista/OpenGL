#pragma once
#pragma comment(lib, "SDL2.lib")

#include <iostream>
#include <GL\glew.h>
#include <SDL.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>

class GameMain
{
private:
	SDL_Window* window;
	SDL_Renderer* renderer;
	SDL_GLContext context;

public:
	GameMain(void);
	GameMain(SDL_Window *window, SDL_Renderer *renderer, SDL_GLContext context);
	~GameMain(void);

	GLboolean finishGame;

	void LoadAssets(void);
	void HandleInput(GLfloat deltaTime);
	void Update(GLfloat deltaTime);
	void Draw(GLfloat deltaTime);
};

