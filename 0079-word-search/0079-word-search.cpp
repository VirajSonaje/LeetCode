class Solution {
public:
    
    bool dfs(int i, int j, vector<vector<char>> &board, string &word, int ind){
        if(board[i][j] == '#') return false;
        // vis[i][j] = true;
        if(ind == word.length()) return true;
        //cout<< board[i][j];
        if(board[i][j] == word[ind]){
            if(ind == word.length()-1) return true;
            bool a = false;
            board[i][j]='#';
                if(i-1 >= 0) a = a||dfs(i-1,j, board, word, ind+1);
                if(j-1>=0) a = a||dfs(i,j-1, board, word, ind+1);
                if(i+1 < board.size()) a= a||  dfs(i+1,j, board, word, ind+1);
                if(j+1 < board[0].size())a = a|| dfs(i,j+1, board, word, ind+1);
            board[i][j]=word[ind];
                return a;
        }
        
        return false;
    }


    bool exist(vector<vector<char>>& board, string word) {
        vector<vector<bool>> vis(board.size(), vector<bool> (board[0].size(), false));
        bool flag = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    //cout<< board[i][j] << dfs(i,j, board, word, 0, vis);
                    if(dfs(i,j, board, word, 0)) flag = true;
                } 
                
            }
        }
        return flag;
    }
};