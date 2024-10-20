#include <stdio.h>
#include <stdlib.h>
#include <SDL.h>
#include "./headers/constants.h"


// -1 indicates no red bar
void renderSort(long (*sortArr)[], int len, SDL_Renderer * renderer, int red) {
    int rectWidth = (int) (WINDOW_WIDTH / len);

    // r, g, b, a values
    // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

    for (int i=0; i < len; i++) {
        int r, g, b;
        if (i == red) {
            r = 255;
            g = 0;
            b = 0;
        } else {
            r = 255;
            g = 255;
            b = 255;
        }
        // height is fraction of screen height (cast all values to float from long)
        float height = ((float)WINDOW_HEIGHT) * (float)((*sortArr)[i] / ((float)len));
        SDL_Rect rect = {
            i * rectWidth,  // x 
            WINDOW_HEIGHT - height,  // y
            rectWidth,  // w
            height,  // h
        };

        SDL_SetRenderDrawColor(renderer, r, g, b, 255);
        SDL_RenderFillRect(renderer, &rect);
    }

    SDL_RenderPresent(renderer);  // swaps buffers
}


void finished(long (*sortArr)[], int len, SDL_Renderer * renderer) {
    int rectWidth = (int) (WINDOW_WIDTH / len);

    // loop partition between green and white bottom to top
    for (int i=0; i < len; i++) {
        // Clear screen
        SDL_SetRenderDrawColor(renderer, 0, 0, 0, 255);
        SDL_RenderClear(renderer);

        // draw rects in reference to partition
        for (int j=0; j < len; j++) {
            int r, g, b;
            if (j <= i) {
                r = 0;
                g = 255;
                b = 0;
            } else {
                r = 255;
                g = 255;
                b = 255;
            }
            // height is fraction of screen height (cast all values to float from long)
            float height = ((float)WINDOW_HEIGHT) * (float)((*sortArr)[j] / ((float)len));
            SDL_Rect rect = {
                j * rectWidth,  // x 
                WINDOW_HEIGHT - height,  // y
                rectWidth,  // w
                height,  // h
            };

            SDL_SetRenderDrawColor(renderer, r, g, b, 255);
            SDL_RenderFillRect(renderer, &rect);
        }

        SDL_RenderPresent(renderer);  // swaps buffers
        SDL_Delay(10);
    }
}
