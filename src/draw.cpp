void prepareScene(void)
{
	SDL_SetRenderDrawColor(app.renderer, 1, 171, 85, 255);
	SDL_RenderClear(app.renderer);
}

void presentScene(void)
{
	SDL_RenderPresent(app.renderer);
}

SDL_Texture *loadTexture(char *filename)
{
	SDL_Texture *texture;

	SDL_LogMessage(SDL_LOG_CATEGORY_APPLICATION, SDL_LOG_PRIORITY_INFO, "Loading %s", filename);

	texture = IMG_LoadTexture(app.renderer, filename);

	return texture;
}

void blit(SDL_Texture *texture, int x, int y)
{
	SDL_Rect dest;

	dest.x = x;
	dest.y = y;
	SDL_QueryTexture(texture, NULL, NULL, &dest.w, &dest.h);

	SDL_RenderCopy(app.renderer, texture, NULL, &dest);
}

void draw_card(SDL_Texture *kaards,card kaard)
{
	SDL_Rect src;
	SDL_Rect dest;

	get_card(kaard);

	src.x = kaard.pos_t.x;
	src.y = kaard.pos_t.y;
	src.w = kaard.size.x;
	src.h = kaard.size.y;

	dest.x=kaard.pos.x;
	dest.y=kaard.pos.y;
	dest.w=kaard.size.x;
	dest.h=kaard.size.y;

	SDL_RenderCopy(app.renderer, kaards, &src, &dest);
}

void draw_back(SDL_Texture *kaards,vec2_i loc,vec2_i size)
{
	SDL_Rect src;
	SDL_Rect dest;

	src.x = 1;
	src.y = 1;
	src.w = size.x;
	src.h = size.y;

	dest.x=loc.x;
	dest.y=loc.y;
	dest.w=size.x;
	dest.h=size.y;

	SDL_RenderCopy(app.renderer, kaards, &src, &dest);
}

void draw_found(SDL_Texture *kaards,vec2_i loc,vec2_i size)
{
	SDL_Rect src;
	SDL_Rect dest;

	src.x = 74;
	src.y = 1;
	src.w = size.x;
	src.h = size.y;

	dest.x=loc.x;
	dest.y=loc.y;
	dest.w=size.x;
	dest.h=size.y;

	SDL_RenderCopy(app.renderer, kaards, &src, &dest);
}