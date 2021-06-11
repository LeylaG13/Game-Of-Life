int **create_2d_array(int rows, int columns);
void initialize(int **array, int rows, int columns);
void random_alive(int **array, int rows, int columns);
void check_alive_or_no(int **array, int rows, int columns, int r, int c, int **copy_array);
void circular(int **array, int rows, int columns);
void check_alive_or_no_clipped(int **array, int rows, int columns, int r, int c, int **array_copy);
void clipped(int **array, int rows, int columns);