#include <stdio.h>
#include <stdlib.h>
#include <CUnit/CUnit.h>
#include <CUnit/CUError.h>
#include <CUnit/TestDB.h>
#include <CUnit/TestRun.h>
#include <CUnit/Automated.h>
#include <CUnit/Basic.h>
#include <CUnit/Console.h>
#include "../Game/life.h"

int *board0[5]; ///initial board
int *board1[5]; ///initial board after clipped
int *board2[5]; ///copy of board 1 (because it is 3 in the morning and we are out of imagination)
int *board3[5]; ///board2 after circular

int init_suite(void) { return 0; }
int clean_suite(void) { return 0; }

void test_board_clipped()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            CU_ASSERT(board0[i][j] == board1[i][j]);
        }
    }
}

void test_board_circular()
{
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            CU_ASSERT(board2[i][j] == board3[i][j]);
        }
    }
}
int main()
{
    CU_pSuite clippedBoardSuite, circularBoardSuite = NULL;

    if (CUE_SUCCESS != CU_initialize_registry())
        return CU_get_error();

    clippedBoardSuite = CU_add_suite("Testing Clipped Game Of Life", init_suite, clean_suite);
    circularBoardSuite = CU_add_suite("Testing Circular Game Of Life", init_suite, clean_suite);

    if (NULL == clippedBoardSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }
    if (NULL == circularBoardSuite)
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    for (int i = 0; i < 5; i++)
        board0[i] = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        board1[i] = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        board2[i] = (int *)malloc(5 * sizeof(int));
    for (int i = 0; i < 5; i++)
        board3[i] = (int *)malloc(5 * sizeof(int));

    ////////////////////////////our initial board
    board0[0][0] = 1;
    board0[0][1] = 0;
    board0[0][2] = 1;
    board0[0][3] = 0;
    board0[0][4] = 1;

    board0[1][0] = 1;
    board0[1][1] = 1;
    board0[1][2] = 1;
    board0[1][3] = 1;
    board0[1][4] = 0;

    board0[2][0] = 0;
    board0[2][1] = 0;
    board0[2][2] = 0;
    board0[2][3] = 1;
    board0[2][4] = 0;

    board0[3][0] = 1;
    board0[3][1] = 1;
    board0[3][2] = 0;
    board0[3][3] = 0;
    board0[3][4] = 1;

    board0[4][0] = 0;
    board0[4][1] = 1;
    board0[4][2] = 1;
    board0[4][3] = 0;
    board0[4][4] = 1;

    ////////////////////////////////////////////////////// manually calculated board0 after clipped function
    board1[0][0] = 1;
    board1[0][1] = 0;
    board1[0][2] = 1;
    board1[0][3] = 0;
    board1[0][4] = 0;

    board1[1][0] = 1;
    board1[1][1] = 0;
    board1[1][2] = 0;
    board1[1][3] = 0;
    board1[1][4] = 1;

    board1[2][0] = 0;
    board1[2][1] = 0;
    board1[2][2] = 0;
    board1[2][3] = 1;
    board1[2][4] = 1;

    board1[3][0] = 1;
    board1[3][1] = 1;
    board1[3][2] = 0;
    board1[3][3] = 0;
    board1[3][4] = 1;

    board1[4][0] = 1;
    board1[4][1] = 1;
    board1[4][2] = 1;
    board1[4][3] = 1;
    board1[4][4] = 0;

    //board 2 is the copy of the board 1,
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            board2[i][j] = board1[i][j];
        }
    }

    /////////////////////////////////////////////////////////////manually calculated board 2 after circular

    board3[0][0] = 0;
    board3[0][1] = 0;
    board3[0][2] = 1;
    board3[0][3] = 0;
    board3[0][4] = 0;

    board3[1][0] = 1;
    board3[1][1] = 1;
    board3[1][2] = 1;
    board3[1][3] = 0;
    board3[1][4] = 0;

    board3[2][0] = 0;
    board3[2][1] = 1;
    board3[2][2] = 1;
    board3[2][3] = 1;
    board3[2][4] = 0;

    board3[3][0] = 0;
    board3[3][1] = 0;
    board3[3][2] = 0;
    board3[3][3] = 0;
    board3[3][4] = 0;

    board3[4][0] = 0;
    board3[4][1] = 0;
    board3[4][2] = 0;
    board3[4][3] = 1;
    board3[4][4] = 0;

    clipped(board0, 5, 5);
    circular(board2, 5, 5);

    if ((NULL == CU_add_test(clippedBoardSuite, "\n\nTesting Clipped Board \n\n", test_board_clipped)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    if ((NULL == CU_add_test(circularBoardSuite, "\n\nTesting Cicular Board\n\n", test_board_circular)))
    {
        CU_cleanup_registry();
        return CU_get_error();
    }

    CU_basic_run_tests(); // OUTPUT to the screen

    CU_cleanup_registry(); //Cleaning the Registry
    return CU_get_error();

    for (int i = 0; i < 5; i++)
    {
        free(board0[i]);
        free(board1[i]);
        free(board2[i]);
        free(board3[i]);
    }
}
