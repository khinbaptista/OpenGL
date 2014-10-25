#pragma once
#pragma comment(lib, "SDL2.lib")

#include <iostream>
#include <GL\glew.h>
#include <SDL.h>
#include <glm\glm.hpp>
#include <glm\gtx\transform.hpp>
#include <glm\gtc\matrix_transform.hpp>
#include "GameMain.h"

#ifdef main
#undef main
#endif


// Global variables

SDL_Window* window;
SDL_Renderer* renderer;
SDL_GLContext context;
GLfloat deltaTime;
GLuint elapsedTime;
GameMain game;

// Initializes everything needed
int Initialize(void);
void InitializeGlew(void);
void InitializeSDL(void);
void CreateWindow(void);
void CreateRenderer(void);
void SetGlAttributes(void);
void CreateContext(void);

void LoadAssets(void);
void Update(void);
void Draw(void);
void Dispose(void);

// Main game loop - program entrance
int main(int argc, char *argv[]);