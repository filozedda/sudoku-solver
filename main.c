#include <stdio.h>

void print_sudoku(int grid[9][9]) {
  for (int i = 0; i < 9; i++) {
    for (int j = 0; j < 9; j++) {
      if (grid[i][j] == 0) {
        printf(". ");
      } else {
        printf("%-2d", grid[i][j]);
      }
      if (j % 3 == 2 && j != 8) {
        printf("|");
      }
    }
    printf("\n");
    if (i % 3 == 2 && i != 8) {
      printf("------+------+------\n");
        }
  }
}

int main(void) {
    int grid[9][9] = {
        {5,3,0,0,7,0,0,0,0},
        {6,0,0,1,9,5,0,0,0},
        {0,9,8,0,0,0,0,6,0},
        {8,0,0,0,6,0,0,0,3},
        {4,0,0,8,0,3,0,0,1},
        {7,0,0,0,2,0,0,0,6},
        {0,6,0,0,0,0,2,8,0},
        {0,0,0,4,1,9,0,0,5},
        {0,0,0,0,8,0,0,7,9}
    };

    print_sudoku(grid);

    return 0;
}
