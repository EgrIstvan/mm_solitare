#include "incl.h"

int main(int argc, char *argv[])
{
    initSDL();

    SDL_Texture* kaards=loadTexture("res/classic-playing-cards.png");

    SDL_Texture* BackFound=loadTexture("res/back_found.png");

    init_deck();
    

	while (1)
	{
		prepareScene();

        draw_field(kaards,BackFound);
        
		doInput();     

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}