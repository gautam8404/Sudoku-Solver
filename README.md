# Sudoku-Solver
A simple Sudoku Solver written in C by using raylib


# Requirements

This program uses raylib for ui so it needs to be installed and included during compiling

https://www.raylib.com/

Linux:- [here](https://github.com/raysan5/raylib/wiki/Working-on-GNU-Linux)

Windows:- [here](https://raysan5.itch.io/raylib/download/eyJleHBpcmVzIjoxNjUzMjYzNTcwLCJpZCI6ODUzMzF9.Vyx50zTfFMC3E8f4zfqg2kgk%2fzk%3d) see (note)[#note] for windows


use `gcc sudoku_solver.c -o sudoku_solver -lraylib` to compile

# Note

.C file won't work in windows as raylib.h and windows.h collide because of having functions with same name, windows users can try .cpp file but make sure they have C++ 11 >=

to compile cpp file use `g++ sudoku_solver.cpp -o sudoku_solver -lraylib`
