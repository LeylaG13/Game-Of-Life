/// @file main.c
/// @mainpage
/// **Developers:** Leyla Gasimova and Laman Mammadova
///
/// **Date:**  11th June, 2021
///
/// **How to run the programm:**
///
/// create folder named "build" (actually you can call it whatever, it is just a convention) \n
/// enter the folder \n
/// open the terminal and run the command: \n
/// cmake .. \n
/// if everything ran succesfully you can run next the command: \n
/// ./GameOfLife \n
/// then input the size of the board you want meaning its columns and rows \n
/// the programm also will ask you which mode of the game you want to play clipped or circular \n
/// For clipped enter 1 \n
/// For circular enter 2 \n
/// Enjoy :) \n

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include "./Game/life.h"
#include "./Console/board_drawer.h"

int main()

{
    srand(time(0));
    int rows, columns, mode;
    puts("Enter number of columns: ");
    scanf("%d", &columns);
    puts("Enter number of rows: ");
    scanf("%d", &rows);

    puts("For mode clipped enter 1, for mode circular enter 2");
    scanf("%d", &mode);

    while (mode != 1 && mode != 2)
    {
        puts("For mode clipped enter 1, for mode circular enter 2");
        scanf("%d", &mode);
    }

    int *arr[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)malloc(columns * sizeof(int));

    initialize(arr, rows, columns);
    random_alive(arr, rows, columns);
    print(arr, rows, columns);

    sleep(2);

    while (1)
    {
        if (mode == 1)
        {
            clipped(arr, rows, columns);
        }
        else
        {
            circular(arr, rows, columns);
        }
        print(arr, rows, columns);
        sleep(1);
    }

    for (int i = 0; i < rows; i++)
        free(arr[i]);
    return 0;
}