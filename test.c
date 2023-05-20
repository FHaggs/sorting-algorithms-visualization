#include <stdlib.h>
#include "raylib.h"
#include <string.h>
#include<unistd.h>


int *initArray(int size){
    int * copy = malloc(sizeof(int)*size);
    
    for(int i=0;i<size;i++){
        int r = (rand() % 440) + 10;
        copy[i] = r;
    }

    return copy;
}

void drawArray(int *arr, int boxWidth){
    int posX = 0;

    for(int i = 0; i < 25; i++){
        posX = boxWidth*i;

        DrawRectangle(posX, GetScreenHeight()-arr[i], boxWidth, arr[i], MAROON);
    }
}


int *bubbleSort(int *array, unsigned size){
    int * copy = malloc(sizeof(int)*size);
    memcpy(copy, array, size * sizeof(int));

    //sort it
    for(int i=0;i<size-1;i++){
        for(int j=0;j < size -1 -i;j++){
            if(copy[j]>copy[j+1]){
                int temp = copy[j];
                copy[j] = copy[j+1];
                copy[j+1] = temp;
                return copy;
            }
        }
    }
    return NULL;
}



int main(void)
{
    int *arr = initArray(25); 

    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 800;
    const int screenHeight = 450;

    const int boxWidth = 32;


    InitWindow(screenWidth, screenHeight, "raylib");


    SetTargetFPS(60);               // Set our game to run at 60 frames-per-second
    //--------------------------------------------------------------------------------------

    // Main game loop
    while (!WindowShouldClose())    // Detect window close button or ESC key
    {
        // Update
        //----------------------------------------------------------------------------------


        // Draw
        //----------------------------------------------------------------------------------
        BeginDrawing();

            if(bubbleSort(arr, 25) != NULL){
                arr = bubbleSort(arr, 25);
                drawArray(arr, 32);
            }else {
                drawArray(arr, 32);
            }

            ClearBackground(RAYWHITE);

            //drawArray(arr, boxWidth);

        EndDrawing();
        //----------------------------------------------------------------------------------
    }

    // De-Initialization
    //--------------------------------------------------------------------------------------
    CloseWindow();        // Close window and OpenGL context
    //--------------------------------------------------------------------------------------

    return 0;
}
