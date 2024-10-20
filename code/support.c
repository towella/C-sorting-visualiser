#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>  // time library
#include <SDL.h>


void renderRect(struct SDL_Renderer *renderer, struct SDL_Rect *rect, int r, int g, int b, int a);

double to_radians(double degrees);
double to_degrees(double radians);

int randomNumber(int min_num, int max_num);


// --- RENDERING ----------------------------------------------------------------------------------------------------

void renderRect(struct SDL_Renderer *renderer, struct SDL_Rect *rect, int r, int g, int b, int a)  {
    SDL_SetRenderDrawColor(renderer, r, g, b, a);
    SDL_RenderFillRect(renderer, rect);
}


// --- ANGLES -------------------------------------------------------------------------------------------------------

double to_radians(double degrees) {
    return degrees * (M_PI / 180);
}

double to_degrees(double radians) {
    return radians * (180 / M_PI);
}


// --- MISC ---------------------------------------------------------------------------------------------------------

// generate cryptographically secure random number (seeded with time which is always changing)
int randomNumber(int min_num, int max_num) {
        int result = 0, low_num = 0, hi_num = 0;

        // validate parameters
        if (min_num < max_num)
        {
            low_num = min_num;
            hi_num = max_num + 1; // include max_num in output
        } else {
            low_num = max_num + 1; // include max_num in output
            hi_num = min_num;
        }

        //srand(time(NULL));  // !!!! seed random with time for cryptographically secure numbers !!!!
        result = (rand() % (hi_num - low_num)) + low_num;  // get result between bounds
        return result;
    }
