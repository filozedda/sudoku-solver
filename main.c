#include <stdio.h>

void print_sudoku(const int grid[9][9]) { //to specify the function doesn't modify the sudoku
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        printf(". ");
      } else {
        printf("%-2d", grid[i][j]);
      }
      if (j % 3 == 2 && j != 8) {
        printf("| ");
      }
    }
    printf("\n");
    if (i % 3 == 2 && i != 8) {
      printf("------+-------+------\n");
        }
  }
}

int read_sudoku(const char *filename, int grid[9][9]) {
    FILE *file = fopen(filename, "r");

    if (file == NULL) {
        printf("Could not open file\n");
        return 0;
    }

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (fscanf(file, "%d", &grid[i][j]) != 1) {
                printf("Reading failed at row %d, column %d\n", i, j);
                fclose(file);
                return 0;
            }
        }
    }

    fclose(file);
    return 1;
}

int main(void) {
    int grid[9][9];
    
    if (read_sudoku("puzzle.txt", grid) == 0) {
        printf("Error reading puzzle\n");
        return 1;
    }
    
    print_sudoku(grid);

    return 0;
}
