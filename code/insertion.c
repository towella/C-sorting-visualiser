#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/constants.h"


void renderSort(long (*sortArr)[], int len, SDL_Renderer * renderer, int red);
void finished(long (*sortArr)[], int len, SDL_Renderer * renderer);


// MARK:  ERROR
void Insertion(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast) {
    // loop through every item
    for (int i=1; i < len; i++) {

        // loop through sorted items to find placement of new item
        int placement = i-1;
        long current = (*sortArr)[i];  // cache current value
        while (placement >= 0 && current < (*sortArr)[placement]) {
            // shuffle up position (by swapping)
            (*sortArr)[placement + 1] = (*sortArr)[placement];
            (*sortArr)[placement] = current;
            placement--;
        }

        // render after pass
        if (fast) {
            renderSort(sortArr, len, renderer, -1);  // -1 indicate no line required    
        } else {
            renderSort(sortArr, len, renderer, i);
            SDL_Delay(SLOW_DELAY);
        }
        SDL_Delay(DELAY);
    }
    finished(sortArr, len, renderer);
}