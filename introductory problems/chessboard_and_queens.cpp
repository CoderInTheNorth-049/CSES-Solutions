#include<bits/stdtr1c++.h>
using namespace std;
int ans;
bool is_safe(vector<string> &board, int row, int col)
{
    if(board[row][col]=='*') return false;

    int i,j;
    for(i=0;i<col;i++)
    {
        if(board[row][i]=='Q') return false;
    }
    for(i=row,j=col;i>=0 && j>=0;i--,j--)
    {
        if(board[i][j]=='Q') return false;
    }
    for(i=row,j=col;j>=0,i<8;i++,j--)
    {
        if(board[i][j]=='Q') return false;
    }

    return true;
    
}

void f(vector<string> &board, int col)
{
    if(col>=8)
    {
        ans+=1;
        return;
    } 

    for(int i=0;i<8;i++)
    {
        if(is_safe(board,i,col))
        {
            board[i][col] = 'Q';
            f(board,col+1);
            board[i][col] = '.';
        }
    }
}

int main()
{
    vector<string> board(8);
    for(int i=0;i<8;i++) cin>>board[i];
    f(board,0);
    cout<<ans<<endl;
}