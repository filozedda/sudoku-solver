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

int valid_values(const int grid[9][9]) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] < 0 || grid[i][j] > 9) {
                return 0;
            }
        }
    }

    return 1;
}

int valid_columns(const int grid[9][9]) {
	for (int j = 0; j < 9; j++) {
		for (int i = 1; i < 9; i++) {
			for (int check = 0; check < i; check++) {
				if (grid[check][j] == grid[i][j] && grid[i][j] != 0) {
				return 0;
			}
		}
	}
}
    return 1;
}

int valid_rows(const int grid[9][9]) {
	for (int i = 0; i < 9; i++) {
		for (int j = 1; j < 9; j++) {
			for (int check = 0; check < j; check++) {
				if (grid[i][check] == grid[i][j] && grid[i][j] != 0) {
				return 0;
			}
		}
	}
}
    return 1;
}

int valid_boxes(const int grid[9][9]) {

    for (int b_rows = 0; b_rows < 9; b_rows += 3) {
        for (int b_columns = 0; b_columns < 9; b_columns += 3) {

            for (int k = 1; k < 9; k++) {

                int row = b_rows + k / 3;
                int col = b_columns + k % 3;

                for (int check = 0; check < k; check++) {

                    int check_row = b_rows + check / 3;
                    int check_col = b_columns + check % 3;

                    if (grid[row][col] == grid[check_row][check_col]
                        && grid[row][col] != 0) {
                        return 0;
                    }
                }
            }
        }
    }

    return 1;
}

int main(void) {
    int grid[9][9];
    
    if (read_sudoku("puzzle.txt", grid) == 0) {
        printf("Error reading puzzle\n");
        return 1;
    }
    
    if (valid_values(grid) == 0 || valid_rows(grid) == 0 || valid_columns(grid) == 0 ||valid_boxes(grid) == 0) {
		printf("This Sudoku is NOT valid\n");
		return 1;
	}
    
    print_sudoku(grid);

    return 0;
}
