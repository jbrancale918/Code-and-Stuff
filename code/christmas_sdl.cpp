/**************************************************
 * I think we should have a fake company name lol *
 **************************************************/

#include <SDL.h>
#include <SDL_image.h>
#include <stdio.h>

#define SCREEN_WIDTH 800
#define SCREEN_HEIGHT 600

int main(int argc, char *argv[])
{
  SDL_Window *window;
  SDL_Surface *screen_surface, *png_surface;

  if (SDL_Init(SDL_INIT_VIDEO) < 0)
  {
    printf("error initializing SDL\n error: %s\n", SDL_GetError());
    return 1;
  }
  else
  {
    // create a window
    window = SDL_CreateWindow("Merry Christmas", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, SCREEN_WIDTH, SCREEN_HEIGHT, SDL_WINDOW_SHOWN);
    if(!window)
    {
      printf("error creating window\n error: %s\n", SDL_GetError());
      SDL_Delay(5000);
      return 1;
    }
    else
    {
      // load png
      if (!(IMG_Init(IMG_INIT_PNG) & IMG_INIT_PNG))
      {
        printf("error loading image\n error: %s\n", SDL_GetError());
        return 1;
      }
      
      // get a surface and shove stuff on the surface and draw to surface
      screen_surface = SDL_GetWindowSurface(window);

      // display png
      png_surface = IMG_Load("../data/christmas.png");
      if (!png_surface)
      {
        printf("error loading image\n error: %s\n", SDL_GetError());
        return 1;
      }

      SDL_BlitSurface(png_surface, 0, screen_surface, 0);
      SDL_UpdateWindowSurface(window);
      
      SDL_Delay(5000);
    }
  }

  return 0;
}

