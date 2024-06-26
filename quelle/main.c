#include <SDL2/SDL.h>
#include <SDL2/SDL_pixels.h>
#include <SDL2/SDL_render.h>
#include <math.h>
#include <stdint.h>
#include <stdio.h>

typedef struct ci64 ci64;
struct ci64 {
  int64_t r;
  int64_t i;
};

#define A 12

void inputcolor(SDL_Renderer *r, int32_t x, int32_t y) {
  double m = sqrt(x * x + y * y) / 256;
  double a = y / (x != 0 ? x : 0.1);
  double tn = atan(a);
  double tna = tn >= 0 ? tn : tn + (M_PI);
  double tna12 = (tna * A/2) / (M_PI);
  double tna12pi = tna12 / (M_PI);
  int t = tna12;
  fprintf(stdout,
          "x = %3d, "
          "y = %3d, "
          "a = %3f, "
          "r = %3f, "
          "t = %3f, "
          "t12 = %f, "
          "t12pi = %f, "
          "t = %d \n",
          x, y, a, m, tna, tna12, tna12pi, t);

  SDL_Color colors[A] = {
      {.r = 255, .g = 000, .b = 000}, // red
      {.r = 255, .g = 128, .b = 000}, // orange
      {.r = 255, .g = 255, .b = 000}, // yellow

      {.r = 128, .g = 255, .b = 000}, // chartette
      {.r = 000, .g = 255, .b = 000}, // green
      {.r = 000, .g = 255, .b = 128}, // spring green

      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
    
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding
      //{.r = 0, .g = 0, .b = 0}, // padding

      {.r = 000, .g = 255, .b = 255}, // cyan
      {.r = 000, .g = 128, .b = 255}, // azure
      {.r = 000, .g = 000, .b = 255}, // blue

      {.r = 128, .g = 000, .b = 255}, // violet
      {.r = 255, .g = 000, .b = 255}, // magenta
      {.r = 255, .g = 000, .b = 128}, // rosa
  };
  SDL_Color c = colors[t + (y < 0 ? 6 : 0)];

  SDL_SetRenderDrawColor(r, 255, 255, 255, 255);
  SDL_SetRenderDrawColor(r, m * c.r, m * c.g, m * c.b, 255);
  SDL_RenderDrawPoint(r, x + 240, y + 240);
}

int main(int argc, const char **argv) {

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
