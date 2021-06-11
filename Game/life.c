#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "life.h"

int **create_2d_array(int rows, int columns)
{
    int **arr = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)malloc(columns * sizeof(int));
    return arr;
}

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

void check_alive_or_no_circular(int **array, int rows, int columns, int r, int c, int **array_copy)
{
    int alive_neighbourhood = 0;
    int up_row;
    int down_row;
    int left_column;
    int right_column;

    if (r != rows - 1 && r != 0)
    {
        up_row = r - 1;
        down_row = r + 1;
    }
    else if (r == rows - 1)
    {
        up_row = r - 1;
        down_row = 0;
    }
    else if (r == 0)
    {
        up_row = rows - 1;
        down_row = r + 1;
    }

    if (c != 0 && c != columns - 1)
    {
        left_column = c - 1;
        right_column = c + 1;
    }
    else if (c == 0)
    {
        left_column = columns - 1;
        right_column = c + 1;
    }
    else if (c == columns - 1)
    {
        left_column = c - 1;
        right_column = 0;
    }

    if (array[down_row][c] == 1)
        alive_neighbourhood++; //up cell
    if (array[up_row][c] == 1)
        alive_neighbourhood++; //down cell
    if (array[r][left_column] == 1)
        alive_neighbourhood++; //left cell
    if (array[r][right_column] == 1)
        alive_neighbourhood++; //right cell
    if (array[up_row][left_column] == 1)
        alive_neighbourhood++; //upper left cell
    if (array[up_row][right_column] == 1)
        alive_neighbourhood++; //uppper right cell
    if (array[down_row][left_column] == 1)
        alive_neighbourhood++; //lower left cell
    if (array[down_row][right_column] == 1)
        alive_neighbourhood++; //lower right cell

    if (alive_neighbourhood == 2 || alive_neighbourhood == 3)
    {
        array_copy[r][c] = 1;
    }
    else
    {
        array_copy[r][c] = 0;
    }
}

void circular(int **array, int rows, int columns)
{
    int **array_copy = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++)
        array_copy[i] = (int *)malloc(columns * sizeof(int));
    initialize(array_copy, rows, columns);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            check_alive_or_no_circular(array, rows, columns, i, j, array_copy);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = array_copy[i][j];
        }
    }

    for (int i = 0; i < rows; i++)
        free(array_copy[i]);
    free(array_copy);
}

void check_alive_or_no_clipped(int **array, int rows, int columns, int r, int c, int **array_copy)
{
    int alive_neighbourhood = 0;
    int up_row = r - 1;
    int down_row = r + 1;
    int left_column = c - 1;
    int right_column = c + 1;

    if (array[down_row][c] == 1)
        alive_neighbourhood++; //up cell
    if (array[up_row][c] == 1)
        alive_neighbourhood++; //down cell
    if (array[r][left_column] == 1)
        alive_neighbourhood++; //left cell
    if (array[r][right_column] == 1)
        alive_neighbourhood++; //right cell
    if (array[up_row][left_column] == 1)
        alive_neighbourhood++; //upper left cell
    if (array[up_row][right_column] == 1)
        alive_neighbourhood++; //uppper right cell
    if (array[down_row][left_column] == 1)
        alive_neighbourhood++; //lower left cell
    if (array[down_row][right_column] == 1)
        alive_neighbourhood++; //lower right cell

    if (alive_neighbourhood == 2 || alive_neighbourhood == 3)
    {
        array_copy[r][c] = 1;
    }
    else
    {
        array_copy[r][c] = 0;
    }
}

void clipped(int **array, int rows, int columns)
{
    int **array_copy = (int **)malloc((rows + 2) * sizeof(int *));
    for (int i = 0; i < rows + 2; i++)
        array_copy[i] = (int *)malloc((columns + 2) * sizeof(int));

    int **array_bigger_copy = (int **)malloc((rows + 2) * sizeof(int *));
    for (int i = 0; i < rows + 2; i++)
        array_bigger_copy[i] = (int *)malloc((columns + 2) * sizeof(int));

    initialize(array_copy, rows, columns);
    initialize(array_bigger_copy, rows + 2, columns + 2);

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array_bigger_copy[i + 1][j + 1] = array[i][j];
        }
    }

    for (int i = 1; i < rows + 1; i++)
    {
        for (int j = 1; j < columns + 1; j++)
        {
            check_alive_or_no_clipped(array_bigger_copy, rows + 1, columns + 1, i, j, array_copy);
        }
    }

    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            array[i][j] = array_copy[i + 1][j + 1];
        }
    }

    for (int i = 0; i < rows + 2; i++)
    {
        free(array_copy[i]);
        free(array_bigger_copy[i]);
    }
    free(array_copy);
    free(array_bigger_copy);
}
