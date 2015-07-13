#include <SDL.h>

#undef main

/*
  TODO(hugo):
  - Smooth the speed of the paddle
  - Detection collision for the paddle (see that it does not get away from the screen)
  - Add a ball to play around with
  - Support Gamepad
 */


int main(int argc, char** argv)
{
    if(SDL_Init(SDL_INIT_AUDIO | SDL_INIT_VIDEO) != 0)
    {
	// TODO(hugo): We can't load SDL. There is an issue.
	return(0);
    }

    int WindowWidth = 500;
    int WindowHeight = 546;
    SDL_Window* Window = SDL_CreateWindow("BRK",
					  SDL_WINDOWPOS_CENTERED,
					  SDL_WINDOWPOS_CENTERED,
					  WindowWidth, WindowHeight, 0);
    SDL_Renderer* Renderer = SDL_CreateRenderer(Window, -1,
						SDL_RENDERER_ACCELERATED);

    SDL_Rect Paddle;
    Paddle.x = 50;
    Paddle.y = 450;
    Paddle.w = 100;
    Paddle.h = 25;
    
    bool GameContinue = true;
    
    while(GameContinue)	
    {
	SDL_Event Event;
	while(SDL_PollEvent(&Event))
	{
	    if(Event.type == SDL_QUIT)
	    {
		GameContinue = false;
	    }
	    if(Event.type == SDL_KEYDOWN)
	    {
		if(Event.key.keysym.scancode == SDL_SCANCODE_LEFT)
		{
		    if(Paddle.x - 4 >= 0)
			Paddle.x -= 4;
		}
		if(Event.key.keysym.scancode == SDL_SCANCODE_RIGHT)
		{
		    if(Paddle.x + Paddle.w + 4 <= WindowWidth)
			Paddle.x += 4;
		}
	    }
	}
	SDL_SetRenderDrawColor(Renderer, 128, 128, 128, 255);	    
	SDL_RenderClear(Renderer);	
	SDL_SetRenderDrawColor(Renderer, 255, 255, 255, 255);
	SDL_RenderFillRect(Renderer, &Paddle);
	SDL_RenderPresent(Renderer);
    }
    
    SDL_DestroyRenderer(Renderer);
    SDL_DestroyWindow(Window);
    SDL_Quit();
    return(0);
}
