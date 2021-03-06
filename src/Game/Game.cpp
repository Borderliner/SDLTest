#include "Game.h"
#include "Logger.h"

Game::Game()
{
	mainWindow = nullptr;
	mainRenderer = nullptr;
	isGameRunning = false; //Bool to check if the game's running
}

Game::~Game()
{

}

bool Game::init(const char* inGameTitle, int inWidth, int inHeight, bool inFullscreen)
{
	Logger::stampDate(); //Stamp the date of this run in Logger.log

	if(SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) >= 0)
	{
		
		Logger::note("SDL Video & Audio initialized successfully!");
		
		//Check if it's fullscreen and set the flags for SDL_CreateWindow
		int flags = 0;
		if(inFullscreen)
			flags = SDL_WINDOW_FULLSCREEN;
		
		mainWindow = SDL_CreateWindow(inGameTitle, SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, inWidth, inHeight, flags);
		
		if(mainWindow != nullptr){
			Logger::note("SDL Window created successfully!");
			
			mainRenderer = SDL_CreateRenderer(mainWindow, -1, SDL_RENDERER_ACCELERATED);
			if(mainRenderer != nullptr)
			{
				Logger::note("SDL Renderer created successfully!");
				SDL_SetRenderDrawColor(mainRenderer, 255, 255, 255, 255); //Set the renderer color to white
			}
			else
			{
				Logger::error("SDL Renderer was failed to be created!");
				return false;
			}
		}
		else
		{
			Logger::error("SDL Window was failed to be created!");
			return false;
		}
	}
	else
	{
		Logger::error("SDL Video & Audio could not be initialized!");
		return false;
	}
	
	Logger::note("SDL is completely loaded.");
	isGameRunning = true; //Everything is alright
	
	//Now set the game window specifications
	gameTitle = inGameTitle;
	width = inWidth;
	height = inHeight;
	
	SDL_Surface* tempSurface = SDL_LoadBMP("Assets/Sprites/cowboyanim.bmp");
	playerTexture = SDL_CreateTextureFromSurface(mainRenderer, tempSurface);
	
	sourceRect.w = 128;
	sourceRect.h = 82;
	sourceRect.x = destRect.x = 0;
	sourceRect.y = destRect.y = 0;
	destRect.w = 128;
	destRect.h = 82;
	
	//We're done here
	return true;
}

bool Game::isRunning()
{
	return isGameRunning;
}

void Game::render()
{
	//Clear out the renderer
	SDL_RenderClear(mainRenderer);
	
	//TODO: Draw here
	SDL_RenderCopy(mainRenderer, playerTexture, &sourceRect, &destRect);
	
	//Draw to the renderer
	SDL_RenderPresent(mainRenderer);
}

void Game::clean()
{
	Logger::note("Clearing the game from memory...");
	SDL_DestroyRenderer(mainRenderer);
	SDL_DestroyWindow(mainWindow);
	SDL_Quit();
}

void Game::handleEvents()
{
	//Create an event handler
	SDL_Event event;
	
	//Check for the events from the last frame
	if(SDL_PollEvent(&event))
	{
		switch (event.type)
		{
			//In case the user has quited the game
			case SDL_QUIT:
				isGameRunning = false;
				break;
			default:
				break;
		}
	}
}

void Game::update()
{
	
}