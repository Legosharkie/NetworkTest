#include <SDL.h>
#include <SDL_net.h>
#include <cstring>
#include <iostream>
#include <string>
#include <fstream>

int main(int argc, char* argv[])
{
	SDL_Init(SDL_INIT_EVERYTHING);
	SDLNet_Init();

	IPaddress ip;
	SDLNet_ResolveHost(&ip, NULL, 1234);

	TCPsocket server = SDLNet_TCP_Open(&ip);
	TCPsocket client = NULL;
	std::string text;
	//const char* text = "HELLO CLIENT";
	while (1)
	{
		if (!client)
			client = SDLNet_TCP_Accept(server);

		if (client)
		{
			std::getline(std::cin, text);
			// communicate with client
			SDLNet_TCP_Send(client, text.c_str(), text.length() + 1);
			SDLNet_TCP_Close(client);
			//break;
		}
	}

	SDLNet_TCP_Close(server);

	SDLNet_Quit();
	SDL_Quit();
	return 0;
}
