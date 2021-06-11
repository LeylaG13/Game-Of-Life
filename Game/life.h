/// @file life.h

/**
 * Allocates 2d array given the number of rows and columns, return double pointer to the array.
 * @param[in] rows
 * @param[in] columns
 * @param[out] pointer_to_2Darray
 */
int **create_2d_array(int rows, int columns);

/**
 * Takes a double pointer to a 2D array, the number of rows and of columns and initializes all elements of the array to 0
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 */
void initialize(int **array, int rows, int columns);

/**
 * Takes a double pointer to a 2D array, the number of rows and of columns and randomly assigns 0 or 1 to all elements
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 */
void random_alive(int **array, int rows, int columns);

/**
 * Takes a double pointer to a 2D array, the number of rows and of columns, index for row and column of specific element and double pointer to the copy of the array
 * The function counts the alive neighbor cells and based on that deducts if the specified cell is alive or dead and changes  it in the copy of the array, not in the original  
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 * @param[in] r
 * @param[in] c
 * @param[in] copy_array 
 */
void check_alive_or_no(int **array, int rows, int columns, int r, int c, int **copy_array);

/**
 * The mode for circular game of life, when we do not consider boundaries
 * Given a double pointer to the 2Darray creates its copy, 
 * then goes into for loop  and checks for each cell if it is alive or no using check_alive_or_no function
 * updates the copy of the array 
 * then updates the original and frees memory from copy
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 */
void circular(int **array, int rows, int columns);

/**
 * Takes a double pointer to a 2D array, the number of rows and of columns, index for row and column of specific element and double pointer to the copy of the array
 * The function counts the alive neighbor cells and based on that deducts if the specified cell is alive or dead and changes  it in the copy of the array, not in the original  
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 * @param[in] r
 * @param[in] c
 * @param[in] copy_array 
 */
void check_alive_or_no_clipped(int **array, int rows, int columns, int r, int c, int **array_copy);

/**
 * The mode for clipped game of life, when we consider boundaries
 * Given a double pointer to the 2Darray creates its copy but which has 2 more rows and columns, and extra rows and columns are initialized to zero (dead cells) 
 * then goes into for loop  and checks for each cell of the bigger copy if it is alive or no using check_alive_or_no_clipped function
 * updates the bigger copy of the array 
 * then updates the original and frees memory from copy
 * @param[in] array
 * @param[in] rows
 * @param[in] columns
 */
void clipped(int **array, int rows, int columns);