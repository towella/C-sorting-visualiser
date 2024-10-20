#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/constants.h"


void renderSort(long (*sortArr)[], int len, SDL_Renderer * renderer, int red);
void finished(long (*sortArr)[], int len, SDL_Renderer * renderer);


void Selection(long (*sortArr)[], int len,  SDL_Renderer * renderer, bool fast) {
    int last = len - 1;
    // while the entire array has not been passed through continue to search
    while (last != 0) {
        long largestIndex = 0;
        // find largest and swap with endmost spot in unsolved array
        for (int j=1; j <= last; j++) {
            if ((*sortArr)[largestIndex] < (*sortArr)[j]) {
                largestIndex = j;

                // render after swap (slow)
                if (!fast) {
                    renderSort(sortArr, len, renderer, j);
                    SDL_Delay(SLOW_DELAY);
                }
            }
        }
        // swap end with largest
        long temp = (*sortArr)[largestIndex];
        (*sortArr)[largestIndex] = (*sortArr)[last];
        (*sortArr)[last] = temp;

        renderSort(sortArr, len, renderer, -1);
        SDL_Delay(DELAY);  // slow down for visualisation

        last--;  // decrement last to reflect solved portion of array
    }
    finished(sortArr, len, renderer);
}