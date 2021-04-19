#include "colors.h"
#include "step1.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void initialize(int **array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = 0;
        }
    }
}

void print(int **array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            if (array[i][j] == 0)
                printf(BRED " %d ", array[i][j]);
            else
                printf(BGRN " %d ", array[i][j]);
        }
        printf(reset "\n");
    }
}

void random_alive(int **array, int rows, int columns)
{
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {

            array[i][j] = rand() % 2;
        }
    }
}
