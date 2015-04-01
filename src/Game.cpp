#include "Game.h"
#include <SDL.h>
#include "Logger.h"

Game::Game()
{
	mainWindow = nullptr;
	mainRenderer = nullptr;
	isGameRunning = false;
}

Game::~Game()
{

}

bool Game::init(const char* inGameTitle, int inWidth, int inHeight, int inFlags)
{
	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0)
	{
		
		Logger::note("SDL Video & Audio initialized successfully!");
		mainWindow = SDL_CreateWindow(inGameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, inWidth, inHeight, inFlags);
		
		if(mainWindow != nullptr){
			Logger::note("SDL Window created successfully!");
			
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if(mainRenderer != nullptr)
				Logger::note("SDL Renderer created successfully!");
		}
	}
	else
	{
		//SDL could not initialize Video & Audio
		return false;
	}
	
	isGameRunning = true;
	gameTitle = inGameTitle;
	width = inWidth;
	height = inHeight;
	return true;
}

bool Game::isRunning()
{
	return isGameRunning;
}
