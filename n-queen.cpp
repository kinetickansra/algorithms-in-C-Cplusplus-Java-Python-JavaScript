#include<bits/stdc++.h>
#define n 4
using namespace std;
bool issafe(int board[n][n], int row, int col)
{
    int i,j;
    for(i=0;i<n;i++)
        if(board[row][i])
            return false;
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
        if(board[i][j])
            return false;
    for(i=row,j=col;i<n && j>=0; i++,j--)
        if(board[i][j])
            return false;

    return true;
}
bool solve(int board[n][n], int col)
{
    if(col>=n)
        return true;
    int i;
    for(i=0;i<n;i++)
    {
        if(issafe(board, i ,col))
            {
                board[i][col]=1;

                if(solve(board, col+1))
                    return true;

                board[i][col]=0;
            }
    }
    return false;
}
int main()
{
    int board[n][n]={{0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0},
                    {0,0,0,0}};
    bool flag;
    int i,j;
    flag=solve(board,0);
    if(flag==false)
        cout<<"solution doesnot exist \n";
    else
    {
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
                cout<<board[i][j]<<" ";
        cout<<"\n";
        }
    }
}
