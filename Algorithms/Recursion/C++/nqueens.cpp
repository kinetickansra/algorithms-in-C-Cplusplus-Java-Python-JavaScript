

#define N 4 
#include<stdio.h> 
#include<stdbool.h> 
  
void printSolution(int board[N][N]) 
{ 
    for (int i = 0; i < N; i++) 
    { 
        for (int j = 0; j < N; j++) 
            printf(" %d ", board[i][j]); 
        printf("\n"); 
    } 
} 
  

bool isSafe(int board[N][N], int row, int col) 
{ 
    int i, j; 
  
    /* Check this row on left side */
    for (i = 0; i < col; i++) 
        if (board[row][i]) 
            return false; 
  
    /* Check upper diagonal on left side */
    for (i=row, j=col; i>=0 && j>=0; i--, j--) 
        if (board[i][j]) 
            return false; 
  
    /* Check lower diagonal on left side */
    for (i=row, j=col; j>=0 && i<N; i++, j--) 
        if (board[i][j]) 
            return false; 
  
    return true; 
} 
