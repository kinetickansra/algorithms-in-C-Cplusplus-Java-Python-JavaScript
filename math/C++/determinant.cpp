#define N 4
#include <bits/stdc++.h> 
using namespace std; 
  

void getCofactor(int mat[N][N], int temp[N][N], int p, int q, int n) 
{ 
    int i = 0, j = 0; 
  
    
    for (int row = 0; row < n; row++) 
    { 
        for (int col = 0; col < n; col++) 
        { 
          
            if (row != p && col != q) 
            { 
                temp[i][j++] = mat[row][col]; 
  
            
                if (j == n - 1) 
                { 
                    j = 0; 
                    i++; 
                } 
            } 
        } 
    } 
} 
