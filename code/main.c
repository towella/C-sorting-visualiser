// https://www.youtube.com/watch?v=XfZ6WrV5Z7Y
// - Make file provides rules that can be run in terminal as shortcuts.
//      - e.g. make build  --> runs the build rule in the file. (indents are important and must be done with tabs)
// https://www.youtube.com/watch?v=V6ACATpl2LQ
// - Get compilation command correct


// --- INCLUDE ---------------------------------------------------------------------------------------------------------
// system files, hence <>
#include <stdio.h>  // I/O
#include <stdlib.h>  // library
#include <stdbool.h>  // boolean
// found in project hence ""
#include <SDL.h>  // init and shutdown
#include "./headers/constants.h"
#include "./headers/sortAlgs.h"
#include "./headers/other.h"


// --- PROTOTYPES ------------------------------------------------------------------------------------------------------
bool initializeWindow(void);
void setup(long (*sortArr)[], int argc, char *argv[]);
void genRandomArr(long (*sortArr)[], int len);
char getInput(void);
void destroyWindow(void);


// --- GLOBAL VARS -----------------------------------------------------------------------------------------------------
bool run = false;
SDL_Window * window = NULL;
SDL_Renderer * renderer = NULL;

int lastFrameTime;


// --- STRUCTS ---------------------------------------------------------------------------------------------------------


// --- MAIN ------------------------------------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
    system("clear");
    
    // get number of sort items
    printf("Number of sort items?");
    char num[20];
    printf("\n> ");
    scanf("%s", num);  // store input at cmd memory address
    int arrLen = atoi(num);
    system("clear");

    // init sort array
    long sortArr[arrLen];

    // get speed of sort
    bool runFast = false;
    printf("Fast? (Y/n) ");
    char cmd = getInput();
    if (cmd == 'Y') {
        runFast = true;
    }
    system("clear");

    // init SDL window and begin loop
    run = initializeWindow();
    while (run) {
        genRandomArr(&sortArr, arrLen);

        system("clear");  // clear terminal
        printf("\nSelect sort:");
        printf("\n- (B)ubble");
        printf("\n- (S)election");
        printf("\n- (I)nsertion");
        printf("\n- (R) Bogosort");
        printf("\n- (Q)uit");
        char cmd = getInput();
        switch (cmd) {
            case 'Q':
                run = false;
                break;
            case 'B':
                Bubble(&sortArr, arrLen, renderer, runFast);
                break;
            case 'S':
                Selection(&sortArr, arrLen, renderer, runFast);
                break;
            case 'I':
                Insertion(&sortArr, arrLen, renderer, runFast);
                break;
            case 'R':
                Bogosort(&sortArr, arrLen, renderer, runFast);
                break;
            default:
                printf("\nInvalid command.\n(Commands are case sensitive)\n");
                SDL_Delay(1500);  // pause before clearing terminal screen
                break;
        }        
    }

    destroyWindow();

    return 0;  // exit success
}


// --- FUNCTIONS -------------------------------------------------------------------------------------------------------

// takes no parameters
bool initializeWindow(void) {
    // init everything via SDL const
    // if an error occurs (0 indicates success), output error
    if (SDL_Init(SDL_INIT_EVERYTHING) != 0) {
        fprintf(stderr, "Error initializing SDL.\n");  // print error to standard error output
        return false;
    }

    // create window
    window = SDL_CreateWindow(
        "My Title",  // pass NULL for no title (like when using flag SDL_WINDOW_BORDERLESS
        SDL_WINDOWPOS_CENTERED,  // otherwise provide x coord
        SDL_WINDOWPOS_CENTERED,  // otherwise provide y coord
        WINDOW_WIDTH,  // width px
        WINDOW_HEIGHT,  // height px
        0  // window flags (i.e. SDL_WINDOW_BORDERLESS)
    );
    // if error from creating window, output error
    if (!window) {
        fprintf(stderr, "Error creating SDL window.\n");
        return false;
    }

    // create renderer
    // window pointer, display driver (-1 is default), flags (0 is none)
    renderer = SDL_CreateRenderer(window, -1, 0);
    // handle error
    if (!renderer) {
        fprintf(stderr, "Error creating SDL renderer.\n");
        return false;
    }

    return true;
}


// sortArr is given as a pointer in order to modify
void setup(long (*sortArr)[], int argc, char *argv[]) {
    for (int i=1; i < argc; i++) {
        (*sortArr)[i-1] = (long) atoi(argv[i]);  // store passed list of numbers (assumed) in sortArr
    }
}


void genRandomArr(long (*sortArr)[], int len) {
    // populate every index of array
    for (int i=0; i < len; i++) {
        double val;
        bool unique = false;  // flag for if number is unique in arr or not
        // keep generating until number is unique
        while (!unique) {
            unique = true;  // assume unique until proven otherwise
            val = (double) randomNumber(1, len);
            // loop up until the point currently populated to ensure number is unique
            for (int j=0; j < i; j++) {
                if (val == (*sortArr)[j]) {
                    unique = false;  // if number is not unique break out and loop again
                    break;
                }
            }
        }
        // once unique number is found, add it to array and move to next position
        (*sortArr)[i] = val;
    }
}


// returns single char NOT string
char getInput(void) {
    // required to allow SDL to run properly
    SDL_Event event;  // event struct
    SDL_PollEvent(&event);  // go check all the inputs

    char cmd[20];
    printf("\n> ");
    scanf("%s", cmd);  // store input at cmd memory address
    return cmd[0];
}


void destroyWindow(void) {
    // remove in REVERSE order to creation :)
    SDL_DestroyRenderer(renderer);
    SDL_DestroyWindow(window);
    SDL_Quit();
}