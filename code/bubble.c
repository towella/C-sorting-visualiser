#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/constants.h"


void renderSort(long (*sortArr)[], int len, SDL_Renderer * renderer, int red);
void finished(long (*sortArr)[], int len, SDL_Renderer * renderer);


void Bubble(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast) {
    bool swapped = true;
    while (swapped) {
        swapped = false;

        for (int i=0; i < len-1; i++) {
            // if swap required, swap
            if ((*sortArr)[i] > (*sortArr)[i+1]) {
                long temp = (*sortArr)[i];
                (*sortArr)[i] = (*sortArr)[i+1];
                (*sortArr)[i+1] = temp;
                swapped = true;
            }

            // render after a swap (slower)
            if (!fast) {
                renderSort(sortArr, len, renderer, i + 1);  // i+1 to highlight value being bubbled up
                SDL_Delay(SLOW_DELAY);
            }
        }

        // render less for speed
        if (fast) {
            renderSort(sortArr, len, renderer, -1);
            SDL_Delay(DELAY);  // slow for visualisation
        }
    }
    finished(sortArr, len, renderer);
}