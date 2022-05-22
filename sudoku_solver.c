#include <stdio.h>
#include "raylib.h"
#include <string.h>
#ifdef _WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif
#define N 9
#ifdef _WIN32
#define sl(S) Sleep(S)
#else
#define sl(S) usleep(S*100)
#endif

const unsigned int WIN_HEIGHT = 900;
const unsigned int WIN_WIDTH = 900;
const unsigned int BOX_H = WIN_HEIGHT/3;
const unsigned int BOX_W = WIN_WIDTH/3;
int cellx = BOX_H/3;
int celly = BOX_W/3;    
const char* title = "Sudoku Solver";


int grid[N][N] = {{3, 0, 6, 5, 0, 8, 4, 0, 0},
                  {5, 2, 0, 0, 0, 0, 0, 0, 0},
                  {0, 8, 7, 0, 0, 0, 0, 3, 1},
                  {0, 0, 3, 0, 1, 0, 0, 8, 0},
                  {9, 0, 0, 8, 6, 3, 0, 0, 5},
                  {0, 5, 0, 0, 9, 0, 6, 0, 0},
                  {1, 3, 0, 0, 0, 0, 2, 5, 0},
                  {0, 0, 0, 0, 0, 0, 0, 7, 4},
                  {0, 0, 5, 2, 0, 6, 3, 0, 0}};




    void print(){
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                printf("%d",grid[i][j]);
            }
            printf("\n");
        }
        
    }


    int possible(int x, int y, int n){
        for (int i = 0; i < N; i++)
        {
            if (grid[x][i] == n)
            {
                return 0;
            }
            
        }
        for (int i = 0; i < N; i++)
        {
            if (grid[i][y] == n)
            {
                return 0;
            }
            
        }
        int x0 = x - x %3;
        int y0 = y - y %3;

        for (int i = 0; i < 3; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (grid[x0 + i][y0 + j] == n)
                {
                    return 0;
                }
                
            }
            
        }
        return 1;
        
    }


    void draw(){
        BeginDrawing(); {
            ClearBackground(RAYWHITE);

            DrawLine(BOX_W ,0,BOX_W,WIN_HEIGHT,BLACK);
            DrawLine(BOX_W + BOX_W ,0,BOX_W + BOX_W,WIN_HEIGHT,BLACK);
            DrawLine(0,BOX_W,WIN_WIDTH,BOX_W,BLACK);
            DrawLine(0,BOX_W + BOX_W,WIN_WIDTH,BOX_W +BOX_W,BLACK);

            char str[10];

            for (int i = 0; i < 9; i++)
            {
            
                for (int j = 0; j < 9; j++)
                {
                    sprintf(str,"%d",grid[i][j]);
                    if (grid[i][j] == 0){
                        strcpy(str," ");
                    }
                    DrawText(str,cellx * j + 40,celly * i+25,50,BLACK);
                }

            }

        }
        EndDrawing();
    }


    void solve(){
        
        while(!WindowShouldClose()){ 

            for (int i = 0; i < N; i++)
            {
                for (int j = 0; j < N; j++)
                {
                    if (grid[i][j] == 0)
                    {
                        for (int n = 1; n < 10; n++)
                        {
                            if (possible(i,j,n))
                            {
                                grid[i][j] = n;
                                draw();
                                BeginDrawing();{
                                    char str[10];
                                    sprintf(str,"%d",grid[i][j]);
                                    DrawText(str,cellx * j + 40,celly * i+25,50,RED);
                                } EndDrawing();
                                sl(1000);
                                solve();
                                grid[i][j] = 0;
                                sl(1000);
                                draw();
                            }

                        }
                        return;

                    }

                }

            }
            // print();
            draw();
        }
        CloseWindow();
        
    }


    int main(){
        InitWindow(WIN_HEIGHT,WIN_WIDTH,title);
        draw();
        solve();
    
    return 0;
   }



