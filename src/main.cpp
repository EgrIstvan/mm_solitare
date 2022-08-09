#include "incl.h"

int main(int argc, char *argv[])
{
    initSDL();

    SDL_Texture* kaards=loadTexture("res/classic-playing-cards.png");

    card heartsfive={
        "diamonds",
        12,
        vec2_i(400,400)
    };

	while (1)
	{
		prepareScene();

        draw_card(kaards,heartsfive);

		doInput();     

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}