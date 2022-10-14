#include <SDL.h>

#pragma once
class Game
{
	public:
		Game();
		~Game();

		void init(const char* title, int xpos, int ypos, int width, int height, int res, double aspect, bool fullScreen);
		
		void handleEvents(int* pause);
		void update();
		void render();
		void clean();
		bool running() { return isRunning; }
		void mousePress(SDL_MouseButtonEvent& b);

	private:
		int windowH, windowW, windowRes, aspectRatio; 
		bool isRunning;
		SDL_Window* window;
		SDL_Renderer* renderer;
		
		SDL_Rect player;
		SDL_Keycode latest_action;
};

