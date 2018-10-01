#include<bits/stdc++.h>
#define n 4
using namespace std;

int sol[n][n]= {{0,0,0,0},
                {0,0,0,0},
                {0,0,0,0},
                {0,0,0,0,}};

void print(int sol[n][n]);

int issafe(int maze[n][n], int row, int col)
{
    if(row>=0 && row<n && col>=0 && col<n && maze[row][col]==1)
            return 1;
    return 0;
}

int solvemaze(int maze[n][n], int row, int col, int sol[n][n])
{
    if(row==n-1 && col==n-1)
    {
        sol[row][col]=1;

        return 1;
    }

    if(issafe(maze,row,col) == 1)
    {

        sol[row][col]=1;
        print(sol);

        if(solvemaze(maze, row, col+1,sol) == 1)
        {
            return 1;
        }
        if(solvemaze(maze, row+1, col,sol) == 1)
        {
            return 1;
        }
        else
        {
            cout<<"Backtracking step \n";
            print(sol);
            sol[row][col]=0;
            return 0;
        }
    }
    return 0;
}


void print(int sol[n][n])
{
    int i,j;

    for(i=0;i<n;i++)
    {
        cout<<"|";
        for(j=0;j<n;j++)
        {
            cout<<" "<<sol[i][j]<<" |";
        }
        cout<<"\n";
    }
    cout<<"\n\n";
}
int main()
{

    /*int maze[n][n]={{1,1,1,0,0,1,1,1},
                    {0,0,1,1,0,0,0,0},
                    {0,0,1,0,0,0,0,0},
                    {0,1,1,1,0,0,0,0},
                    {0,0,0,1,0,0,0,0},
                    {0,0,0,1,0,1,1,1},
                    {0,0,0,1,0,1,0,1},
                    {0,0,0,1,1,1,0,1}};


    int sol[n][n] ={{0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0},
                    {0,0,0,0,0,0,0,0}};*/

        int maze[n][n]={{1,1,1,0},
                        {0,1,0,1},
                        {0,1,1,0},
                        {0,1,1,1}};


    cout<<"Maze"<<"\n";
    print(maze);

    solvemaze(maze,0,0,sol);


    print(sol);

}
