#include <iostream>
#include <utility>
#include <vector>
#include <algorithm>
#include <map>
#include <string>
#include <cstdlib>
#include <time.h>
#include <cstdio>
#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define SCREEN_WIDTH   774
#define SCREEN_HEIGHT  580

typedef struct {
	SDL_Renderer *renderer;
	SDL_Window *window;
} App;

typedef struct {
	int x;
	int y;
	SDL_Texture *texture;
} Entity;

struct vec2_i {
    float x;
    float y;
	vec2_i(float a,float b):x(a), y(b){}
};

struct card {
	std::string suit;
	int val;
	vec2_i pos;
	vec2_i pos_t=vec2_i(0,0);
	vec2_i size=vec2_i(72,96);
};

struct deck {
	std::vector<card> c;
};

struct Field{
	deck stock;
	deck waste;
	deck foundation[4];
	deck tableau[7];
	int hidden[7];
};

Field field;
App app;

bool grnd=false;

#include "init_deck.cpp"
#include "get_card.cpp"
#include "draw.cpp"
#include "draw_field.cpp"
#include "init.cpp"
#include "input.cpp"