/*===================================================================#
| 'Main' source file last updated on 11 May 2021                     |
#===================================================================*/

#include "Game.h"
#include "MenuState.h"

int main(int argc, char* args[])
{
	Game* game = new Game(new MenuState);

	if (!(game->Initialize("<insert game name here>", 1280, 720)))
	{
		return 0;
	}

	if (!game->Run())
	{
		return 0;
	}

	game->Shutdown();

	return 0;
}