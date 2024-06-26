#include <SDL2/SDL_render.h>
#include <stdint.h>
#include <SDL2/SDL.h>

typedef struct ci64 ci64;
struct ci64 {
  int64_t r;
  int64_t i;
};

int main(int argc, const char **argv) {

  uint64_t width = 480 * 2 + 1;
  uint64_t height = 480;
  SDL_Window * window;
  SDL_Renderer * renderer;
  SDL_Init(SDL_INIT_EVERYTHING);
	SDL_CreateWindowAndRenderer(width,height,0,&window,&renderer);
	SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_RenderPresent(renderer);
  SDL_SetRenderDrawColor(renderer,0,0,0,255);
	SDL_RenderClear(renderer);
	SDL_SetRenderDrawColor(renderer,255,255,255,255);
  SDL_RenderDrawPoint(renderer, 0, 0);
	SDL_RenderPresent(renderer);
	SDL_Delay(1024 + 512);
	SDL_Quit();

  return 0;
}
