#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  // time library
#include <SDL.h>


void renderRect(struct SDL_Renderer *renderer, struct SDL_Rect *rect, int r, int g, int b, int a);

double to_radians(double degrees);
double to_degrees(double radians);

int randomNumber(int min_num, int max_num);

