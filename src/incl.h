#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH   1280
#define SCREEN_HEIGHT  720

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;

App app;

bool grnd=false;

#include "draw.cpp"
#include "init.cpp"
#include "input.cpp"