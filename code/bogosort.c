#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <SDL.h>
#include "./headers/constants.h"
#include "./headers/other.h"


void renderSort(long (*sortArr)[], int len, SDL_Renderer * renderer, int red);
void finished(long (*sortArr)[], int len, SDL_Renderer * renderer);

void genRandomIndexArr(int (*arr)[], int len);


void Bogosort(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast) {
    bool run = true;
    while (run) {
        int randIndicies[len];
        genRandomIndexArr(&randIndicies, len);

        // randomly reorder array based on randomised index array
        for (int i=0; i < len-1; i++) {
            long temp = (*sortArr)[randIndicies[i]];
            (*sortArr)[randIndicies[i]] = (*sortArr)[randIndicies[i+1]];
            (*sortArr)[randIndicies[i+1]] = temp;
        }

        // check if solved
        run = false;  // assume done
        for (int i=0; i < len-1; i++) {
            // if not yet ordered correctly, continue
            if ((*sortArr)[i] > (*sortArr)[i+1]) {
                run = true;
                break;
            }
        }
        renderSort(sortArr, len, renderer, -1);
        if (!fast) {
            SDL_Delay(SLOW_DELAY);
        }
        SDL_Delay(DELAY);
    }
    finished(sortArr, len, renderer);
}


void genRandomIndexArr(int (*arr)[], int len) {
    // populate every index of array
    for (int i=0; i < len; i++) {
        int val;
        bool unique = false;  // flag for if number is unique in arr or not
        // keep generating until number is unique
        while (!unique) {
            unique = true;  // assume unique until proven otherwise
            val = randomNumber(0, len-1);
            // loop up until the point currently populated to ensure number is unique
            for (int j=0; j < i; j++) {
                if (val == (*arr)[j]) {
                    unique = false;  // if number is not unique break out and loop again
                    break;
                }
            }
        }
        // once unique number is found, add it to array and move to next position
        (*arr)[i] = val;
    }
}