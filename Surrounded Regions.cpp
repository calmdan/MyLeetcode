//一开始的想法从内部向外面找，找不到则标记为死点
//既然外面已经确定有活点，从活点找更好
class Solution {
public:
    void solve(vector<vector<char>> &board) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() function
        int m = board.size();
        if(m<=2)return;
        int n = board[0].size();
        if(n<=2)return;
        for(int i=0;i<m;i++)
        {
            if(board[i][0]=='O') mark(board,i,0);
            if(board[i][n-1]=='O') mark(board,i,n-1);
        }
        for(int i=0;i<n;i++)
        {
            if(board[0][i]=='O') mark(board,0,i);
            if(board[n-1][i]=='O') mark(board,n-1,i);
        }

        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]=='O') board[i][j]='X';
                if(board[i][j]=='d') board[i][j]='O';
            }
        }
    }
    void mark( vector<vector<char>> &board,int i, int j)
    {
        board[i][j] = 'd';
        if(i-1>=0 && board[i-1][j]=='O') mark(board,i-1,j);
        if(i+1<board.size() && board[i+1][j]=='O') mark(board,i+1,j);
        if(j-1>=0 && board[i][j-1]=='O') mark(board,i,j-1);
        if(j+1<board[0].size() && board[i][j+1]=='O') mark(board,i,j+1);
        return;
    }
};
