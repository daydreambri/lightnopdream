#include <SDL.h>
#include <iostream>

int main(int argc, char*argv[])
{
	SDL_Window *window = nullptr;
	SDL_Surface *windowSurface = nullptr;
	SDL_Surface *imageSurface = nullptr;

	if (SDL_Init(SDL_INIT_VIDEO) < 0)
		std::cout << "Video Initialization Error: " << SDL_GetError() << std::endl;
	else
	{
		window = SDL_CreateWindow("LightNopDream", SDL_WINDOWPOS_CENTERED, SDL_WINDOWPOS_CENTERED, 640, 480, SDL_WINDOW_SHOWN);
		if (window == NULL)
			std::cout << "Window creation error: " << SDL_GetError() << std::endl;
		else
		{
			//Window created
			windowSurface = SDL_GetWindowSurface(window);
			imageSurface = SDL_LoadBMP("derp.bmp");

			if (imageSurface == NULL)
				std::cout << "Image loading error: " << SDL_GetError() << std::endl;
			else
			{
				SDL_BlitSurface(imageSurface, NULL, windowSurface, NULL);
				SDL_UpdateWindowSurface(window);
				SDL_Delay(3000);

			}
		}
	}

	SDL_FreeSurface(imageSurface);
	imageSurface = nullptr;
	SDL_DestroyWindow(window);
	window = nullptr;
	windowSurface = nullptr;

	SDL_Quit();

	return 0;
}