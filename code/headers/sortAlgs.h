#include <stdlib.h>
#include <stdio.h>
#include <SDL.h>
#include <stdbool.h>
#include "constants.h"

// --- INCLUDE ---

// --- STRUCT DECLARATIONS ---

// --- FUNC DECLARATIONS ---
// bubble.c
void Bubble(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast);

// insertion.c
void Insertion(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast);

// selection.c
void Selection(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast);

// bogosort.c
void Bogosort(long (*sortArr)[], int len, SDL_Renderer * renderer, bool fast);
