#pragma comment (lib, "glew32.lib")

#include "main.h"

using namespace std;

int Initialize(void){
	deltaTime = 0.0f;
	elapsedTime = 0;
	
	// Create everything we need in order to use this program
	InitializeSDL();
	CreateWindow();
	CreateRenderer();
	SetGlAttributes();
	CreateContext();
	InitializeGlew();

	// User defined initialization
	game = *new GameMain(window, renderer, context);
	LoadAssets();

	return 0;
}

void InitializeGlew(void){
	glewExperimental = GL_TRUE;

	GLenum glewInitResult = glewInit();

	if (glewInitResult != GLEW_OK){
		cout << "GLEW Error: " << glewGetErrorString(glewInitResult) << endl;
		SDL_Quit();
		getchar(); exit(1);
	}

	cout << "GLEW initialized OK!" << endl;
}

void InitializeSDL(void){
	if (SDL_Init(SDL_INIT_EVERYTHING) != 0){
		cout << "SDL init error: " << SDL_GetError() << endl;
		getchar(); exit(1);
	}
	cout << "SDL Init OK!" << endl;
}

void CreateWindow(void){
	window = SDL_CreateWindow("< GAME TITLE HERE >",
		SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 1600, 900,
		SDL_WINDOW_SHOWN | SDL_WINDOW_OPENGL);

	if (window == nullptr){
		cout << "SDL_CreateWindow error: " << SDL_GetError() << endl;
		SDL_Quit();
		getchar(); exit(1);
	}

	cout << "Window created OK!" << endl;

	SDL_ShowCursor(SDL_DISABLE);
}

void CreateRenderer(void){
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED | SDL_RENDERER_PRESENTVSYNC);

	if (renderer == nullptr){
		SDL_DestroyWindow(window);
		cout << "SDL_CreateRenderer error: " << SDL_GetError() << endl;
		getchar(); exit(1);
	}

	cout << "Renderer created OK!" << endl;
}

void SetGlAttributes(void){
	int major = 3;
	int minor = 3;

	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MAJOR_VERSION, major);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_MINOR_VERSION, minor);
	SDL_GL_SetAttribute(SDL_GL_CONTEXT_PROFILE_MASK, SDL_GL_CONTEXT_PROFILE_CORE);

	cout << "OpenGL context version: " << major << "." << minor << endl;
}

void CreateContext(void){
	context = SDL_GL_CreateContext(window);

	if (context == nullptr){
		SDL_DestroyWindow(window);
		cout << "Create context error: " << SDL_GetError() << endl;
		SDL_Quit();
		getchar(); exit(1);
	}

	cout << "Created OpenGL context OK!" << endl;
}

int main(int argc, char *argv[]){
	Initialize();

	while (game.finishGame != GL_TRUE){
		Update();
		Draw();
		SDL_GL_SwapWindow(window);
	}

	Dispose();
	
	return 0;
}


// Load assets to your game
void LoadAssets(void){
	game.LoadAssets();
}

// Update game logic, including end conditions (the 'finish' variable)
void Update(void){
	GLfloat lastTicksElapsed = GLfloat(elapsedTime);
	elapsedTime = SDL_GetTicks();

	// Calculate delta time in seconds
	deltaTime = GLfloat(elapsedTime - lastTicksElapsed) / 1000.0f;

	game.Update(deltaTime);
}

// Draw the game at the current state
void Draw(void){
	game.Draw(deltaTime);
}

// Clean up
void Dispose(void){
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);

	delete &game;
}