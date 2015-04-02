#ifndef GAME_H
#define GAME_H
#include <SDL.h>

class Game
{
public:
	Game();
	~Game();
	bool init(const char* inGameTitle, int inWidth, int inHeight, int inFlags);
	void handleEvents();
	void update();
	void render();
	void clean();
	bool isRunning();
	
private:
	SDL_Window* mainWindow;
	SDL_Renderer* mainRenderer;
	bool isGameRunning;
	const char* gameTitle;
	int width;
	int height;
	
};

#endif // GAME_H
