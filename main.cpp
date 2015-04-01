#include "src/Game.h"

Game* game = nullptr;

int main(int argc, char** argv)
{
	game = new Game();
	game -> init("My Game", 800, 600, SDL_WINDOW_SHOWN);
	while(game->isRunning())
	{
		game -> handleEvents();
		game -> update();
		game -> render();
	}
	
	game ->clean();
	return 0;
}