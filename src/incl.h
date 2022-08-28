#include <iostream>
#include <array>
#include <utility>
#include <vector>
#include <algorithm>
#include <iterator>
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

struct vec2_int {
    int x;
    int y;
	vec2_int(int a,int b):x(a), y(b){}
};

struct aabb {
	vec2_i b;
	vec2_i e;
	aabb(vec2_i a,vec2_i b):b(a), e(b){}
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

struct FieldColl{
	aabb stock=aabb(vec2_i(0,0),vec2_i(0,0));
	aabb waste=aabb(vec2_i(0,0),vec2_i(0,0));
	aabb foundation[4]={aabb(vec2_i(0,0),vec2_i(0,0)),aabb(vec2_i(0,0),vec2_i(0,0)),aabb(vec2_i(0,0),vec2_i(0,0)),aabb(vec2_i(0,0),vec2_i(0,0))};
	std::vector<aabb> tableau[7];
};

Field field;
FieldColl field_coll;
deck holding;

App app;

bool grnd=false;

#include "init_deck.cpp"
#include "get_card.cpp"
#include "draw.cpp"
#include "draw_field.cpp"
#include "init.cpp"
#include "mouse_in.cpp"
#include "input.cpp"