#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "step1.h"

int main()

{
    srand(time(0));
    int rows, columns, alive;
    puts("Enter number of columns: ");
    scanf("%d", &columns);
    puts("Enter number of rows: ");
    scanf("%d", &rows);

    int *arr[rows];
    for (int i = 0; i < rows; i++)
        arr[i] = (int *)malloc(columns * sizeof(int));

    initialize(arr, rows, columns);
    random_alive(arr, rows, columns);
    print(arr, rows, columns);

    for (int i = 0; i < rows; i++)
        free(arr[i]);
    return 0;
}