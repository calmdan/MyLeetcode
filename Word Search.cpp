class Solution {
public:
    bool exist(vector<vector<char> > &board, string word) {
        // Start typing your C/C++ solution below
        // DO NOT write int main() DFStion
        if(word.length()==0)return true;
        int m = board.size();
        int n = board[0].size();
        vector<vector<bool> > used(m,vector<bool>(n,false));
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(word[0]==board[i][j]) 
                {
                    
                    if(DFS(board,used,word,i,j,0)) return true;
                }
            }
        }
        return false;
    }
    bool DFS(vector<vector<char> > &board,vector<vector<bool> > &used, string &word, int i, int j, int dep)
    {
        used[i][j]=true;
        if(dep == word.length()-1) return true;
    
        if(i-1>=0 && board[i-1][j]==word[dep+1] && used[i-1][j]==false) 
        {
            if(DFS(board,used,word,i-1,j,dep+1)) return true;
            used[i-1][j]=false;
        }
        if(i+1<board.size()  && board[i+1][j]==word[dep+1] && used[i+1][j]==false) 
        {
            if(DFS(board,used,word,i+1,j,dep+1)) return true;
            used[i+1][j]=false;
        }
        if(j-1>=0 && board[i][j-1]==word[dep+1] && used[i][j-1]==false) 
        {
            if(DFS(board,used,word,i,j-1,dep+1)) return true;
            used[i][j-1]=false;
        }
        if(j+1<board[0].size() && board[i][j+1]==word[dep+1] &&used[i][j+1]==false) 
        {
            if(DFS(board,used,word,i,j+1,dep+1)) return true;
            used[i][j+1]=false;
        }
        used[i][j]=false;
        return false;
    }
};
