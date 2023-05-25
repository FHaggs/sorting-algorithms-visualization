#include <stdlib.h>
#include <stdio.h>
#include "raylib.h"
#include <string.h>
#include<unistd.h>
#include <time.h>

void suffleArray (int *arr, int size){

    int rand_index;

    srand(time(NULL));

    for(int i=0;i<size;i++){
        rand_index = rand() % size;
        int temp = arr[i];
        arr[i] = arr[rand_index];
        arr[rand_index] = temp;
    }
}
int *initArray(int size){
    int * copy = malloc(sizeof(int) * size);

    for(int i=0;i<size;i++){
        int r = 20*i;
        copy[i] = r;
    }
    return copy;
}

void drawArray(int *arr, int size,int boxWidth){
    int posX = 0;

    for(int i = 0; i < size; i++){
        posX = boxWidth*i;

        DrawRectangle(posX, GetScreenHeight()-arr[i], boxWidth, arr[i], MAROON);
    }
}


int *bubbleSort(int *array, unsigned size){
    int * copy = malloc(sizeof(int) * size);
    memcpy(copy, array, size * sizeof(int));

    //free(array);
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
    int arr_length = 50;
    int *arr;
    arr = initArray(arr_length); 
    int ARR_SIZE = arr_length;

    printf("%d \n", ARR_SIZE);
    suffleArray(arr, ARR_SIZE);
    // Initialization
    //--------------------------------------------------------------------------------------
    const int screenWidth = 2000;
    const int screenHeight = 1000;

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
        DrawText("Comands: B = bubbleSort S = Suffle", 1605, 10, 20, DARKGRAY);

        BeginDrawing();
            if (IsKeyDown(KEY_B)) {

                if(bubbleSort(arr, ARR_SIZE) != NULL){
                    arr = bubbleSort(arr, ARR_SIZE);
                    drawArray(arr, ARR_SIZE,boxWidth);
                }else {
                    drawArray(arr, ARR_SIZE, boxWidth);
                }
            } else {
                    drawArray(arr, ARR_SIZE, boxWidth);
            }
    
            if(IsKeyDown(KEY_S)){
                suffleArray(arr, ARR_SIZE);
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
    free(arr);

    return 0;
}
