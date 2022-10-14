#include <SDL.h>
#include <SDL_net.h>
#include <cstring>
#include <iostream>

int main(int argc, char* argv[])
{

	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip, "10.8.5.221", 1234);

	TCPsocket client = SDLNet_TCP_Open(&ip);
	char text[100];
	SDLNet_TCP_Recv(client, text, 100);
	std::cout << text << std::endl;

	SDLNet_TCP_Close(client);

	SDLNet_Quit();
	SDL_Quit();
	return 0;
}
