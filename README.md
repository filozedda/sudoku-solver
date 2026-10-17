# Sudoku Solver in C

A command-line Sudoku solver written in C using recursive backtracking.

I built this project to practice C programming, recursion, file input, validation, and basic algorithm analysis.

## Features

- Reads a Sudoku puzzle from a text file
- Checks that all values are between 0 and 9
- Detects duplicates in rows, columns, and 3×3 boxes
- Solves valid puzzles using recursive backtracking
- Detects puzzles with no solution
- Tracks:
  - number of recursive calls
  - number of backtracks
  - execution time

## Input Format

The puzzle is stored as a 9×9 grid of integers.

`0` represents an empty cell.

Example:

```text
5 3 0 0 7 0 0 0 0
6 0 0 1 9 5 0 0 0
0 9 8 0 0 0 0 6 0
8 0 0 0 6 0 0 0 3
4 0 0 8 0 3 0 0 1
7 0 0 0 2 0 0 0 6
0 6 0 0 0 0 2 8 0
0 0 0 4 1 9 0 0 5
0 0 0 0 8 0 0 7 9
```

## Algorithm

The solver uses recursive backtracking.

For each empty cell, it tries the values from 1 to 9.

A value can be placed only if it does not already appear in:

- the same row
- the same column
- the same 3×3 box

If a choice eventually leads to a position with no valid continuation, the program removes that value and tries another one.

The process continues until either the Sudoku is solved or every possible choice has failed.

## Compilation

Using GCC:

```bash
gcc main.c -o sudoku
```

On Windows:

```bash
.\sudoku.exe
```

## Tests

I tested the solver on puzzles with different characteristics.

| Puzzle | Recursive calls | Backtracks | Execution time |
|---|---:|---:|---:|
| Easy | 4209 | 4157 | 0.001000 s |
| Hard | 8970 | 8911 | 0.002000 s |
| Invalid | Rejected during validation | — | — |

The harder puzzle required more than twice as many recursive calls as the easier puzzle with the current search strategy.

The execution times are very small, so recursive calls and backtracks are more useful for comparing the behavior of the algorithm at this scale.

## Project Structure

```text
sudoku-solver/
├── main.c
├── README.md
└── puzzles/
    ├── easy.txt
    ├── hard.txt
    └── invalid.txt
```

## Possible Improvements

Some possible future improvements are:

- Allow the input filename to be given from the command line
- Add more test puzzles
- Detect whether a puzzle has multiple solutions
- Improve the search strategy by choosing constrained cells first
- Compare different solving strategies

## What I Learned

This project helped me practice:

- multidimensional arrays
- functions
- file handling with `fopen`, `fscanf`, and `fclose`
- `struct`
- recursion
- backtracking
- input validation
- measuring simple algorithm statistics
- using Git and GitHub