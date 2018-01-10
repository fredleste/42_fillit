# fillit

- Create main.c

- Create variables in main :
  - t_tetras[19] tetras_lib : library of the 19 distincts tetraminos
  - short int* tetras : dynamic array of tetriminos
  - int tetras_length : length of tetras_lib
  - char[16][16] grid : grid to fill
  - int grid_length : size of the grid

- Create functions in main :

  - void init_tetras_lib(t_tetra[19] tetras_lib)
    The function will create the tetriminos library.

  - int test_params(int argc)
    - return (0) and write "usage" on standard output if the number of arguments is not 1
    - return (1) if the number of arguments is 1

  - int test_source(char* file_name, t_tetra[19] tetras_lib, short int* tetras)
    - file_name is the first argument
    - tetras_lib is the library of the 19 distincts tetraminos existing.
    - tetras is a pointer on short int. It will contains all tetriminos.
    The function :
    - returns (-1) and writes "error" on standard output if the source file is not valid
    - returns (tetras_length) if the source file is valid
    - RQ a file is valid if :
      - it exists
      - it contains only tetriminos (0 to 26)

  - int get_grid(short int* tetras, unsigned int tetras_length, char[16][16] grid)
    - return (-1) if something is wrong
    - return (grid_length) if the square is found.

  - void write_grid(char[16][16] grid, int grig_length)
    - write the square on the standard output

- Create main.h
  will contains all the needed libraries and include files

- Create tetras_lib.c & tetras_lib.h
  will contain all code to construct init_tetras_lib

- Create test.c & test.h
  will contain all code to test input

- Create grid.c & grid.h
  will contain all code to get the grid (backtracking)

- Create output.c & output.h
  will contain all code about outputs

  ------------------------------------------------------------------------------
  - tests_params
  	+ usage
