#include "GameMain.h"

GameMain::GameMain(void){
	std::cout << "Game Main created empty. Useless." << std::endl;
	getchar(); exit(1);
}

GameMain::GameMain(SDL_Window *window, SDL_Renderer *renderer, SDL_GLContext context){
	this->window = window;
	this->renderer = renderer;
	this->context = context;

	finishGame = GL_FALSE;
}

GameMain::~GameMain(void){

}

void GameMain::LoadAssets(void){

}

void GameMain::Update(GLfloat deltaTime){

}

void GameMain::Draw(GLfloat deltaTime){

}