#include "incl.h"

int main(int argc, char *argv[])
{
    initSDL();

	while (1)
	{
		prepareScene();

		doInput();     

		presentScene();

		SDL_Delay(16);
	}

	return 0;
}