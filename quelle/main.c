#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <signal.h>
#include <stdint.h>
#include <stdio.h>

#define count(a) (sizeof(a) / sizeof(typeof(a[0])))

typedef struct polari polari;
struct polari {
  double raggio;
  double theta;
};

polari fromCartesiane(int x, int y) {
  double t = atan2(y, (x != 0 ? x : 0.1));
  polari a = {
      .raggio = sqrt(x * x + y * y),
      .theta = t + (0 <= t ? 0 : M_PI),
  };
  return a;
}

void inputcolor(SDL_Renderer *r, int32_t x, int32_t y) {

  SDL_Color colors[] = {
      {.r = 255, .g = 000, .b = 000}, // red
      {.r = 255, .g = 128, .b = 000}, // orange
      {.r = 255, .g = 255, .b = 000}, // yellow

      {.r = 128, .g = 255, .b = 000}, // chartette
      {.r = 000, .g = 255, .b = 000}, // green
      {.r = 000, .g = 255, .b = 128}, // spring green

      {.r = 000, .g = 255, .b = 255}, // cyan
      {.r = 000, .g = 128, .b = 255}, // azure
      {.r = 000, .g = 000, .b = 255}, // blue

      {.r = 128, .g = 000, .b = 255}, // violet
      {.r = 255, .g = 000, .b = 255}, // magenta
      {.r = 255, .g = 000, .b = 128}, // rosa
  };

  polari p = fromCartesiane(x, y);
  double m = p.raggio / 256;
  int t = (p.theta * (count(colors)) / 2) / M_PI + (y < 0 ? 6 : 0);
  SDL_Color *c = &(colors[t]);

  SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
  SDL_SetRenderDrawColor(r, m * c->r, m * c->g, m * c->b, 255);
  SDL_RenderDrawPoint(r, x + 240, y + 240);

}

void die(int sig) { exit(1); }

int main(int argc, const char **argv) {

  signal(SIGINT, die);

  uint64_t width = 481 * 2 + 1;
  uint64_t height = 481;
  SDL_Window *window;
  SDL_Renderer *renderer;
  SDL_Init(SDL_INIT_EVERYTHING);
  SDL_CreateWindowAndRenderer(width, height, 0, &window, &renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_RenderPresent(renderer);
  SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
  SDL_RenderClear(renderer);
  SDL_SetRenderDrawColor(renderer, 255, 255, 255, 255);
  // SDL_RenderDrawPoint(renderer, 0, 0);
  int min = -240, max = 240;
  for (int i = min; i < max; i++) {
    for (int j = min; j < max; j++) {
      inputcolor(renderer, j, i);
    }
  }
  SDL_RenderPresent(renderer);
  SDL_Delay(1024 * 32 + 512);
  SDL_Quit();

  return 0;
}

