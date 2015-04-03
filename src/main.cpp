#include "Game/Game.h"


int main(int argc, char** argv)
{
	Game game;
	game.init("My Game", 800, 600, false);
	while(game.isRunning())
	{
		game.handleEvents();
		game.update();
		game.render();
	}
	
	game.clean();
	return 0;
}