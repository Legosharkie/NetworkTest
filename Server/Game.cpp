#include "Game.h"
#include <iostream>

Game::Game()
{
	player.x = 0;
	player.y = 0;
	player.w = 100;
	player.h = 100;
	latest_action = SDLK_d;
}

Game::~Game()
{

}


void Game::init(const char* title, int xpos, int ypos, int width, int height, int res, double aspect, bool fullScreen)
{
	int flags = 0;
	
	if (fullScreen)
	{
		flags = SDL_WINDOW_FULLSCREEN;
	}

	windowRes = res;
	aspectRatio = aspect;

	if (SDL_Init(SDL_INIT_EVERYTHING) == 0)
	{
		std::cout << "Initializing..." << std::endl;
		window = SDL_CreateWindow(title, xpos, ypos, width, height, flags);
		SDL_GetWindowSize(window, &windowW, &windowH);
		if (window)
		{
			std::cout << "Window created!" << std::endl;
		}

		renderer = SDL_CreateRenderer(window, -1, 0);
		if (renderer)
		{
			SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
			std::cout << "Renderer created!" << std::endl;
		}

		isRunning = true;
	}
	else
	{
		isRunning = false;
	}
}

void Game::handleEvents(int *pause)
{
	SDL_Event event;

	SDL_PollEvent(&event);
	//const Uint8* state = SDL_GetKeyboardState(NULL);

	switch (event.type)
	{
		case SDL_MOUSEBUTTONDOWN:
			mousePress(event.button);
			break;
		case SDL_KEYDOWN:
			if (event.key.keysym.sym == SDLK_p)
			{
				*pause = !(*pause);
				break;
			}
			break;
		case SDL_QUIT:
			isRunning = false;
			break;
		
		default:
			break;
	}
}
 
void Game::update()
{

}

void Game::render()
{
	SDL_SetRenderDrawColor(renderer, 0, 0, 0, SDL_ALPHA_OPAQUE);
	SDL_RenderClear(renderer);

	/* INSERT CODE HERE */

	SDL_RenderPresent(renderer);
}

void Game::clean()
{
	SDL_DestroyWindow(window);
	SDL_DestroyRenderer(renderer);
	SDL_Quit();
	std::cout << "Window destroyed!" << std::endl;
}



void Game::mousePress(SDL_MouseButtonEvent& b)
{
	int x, y;
	int ix, iy;
	if (b.button == SDL_BUTTON_LEFT)
	{
		SDL_GetMouseState(&x, &y);
		std::cout << "Hej @ <" << x << ", " << y << ">" << std::endl;
	}
}