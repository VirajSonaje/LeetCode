class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {
        bool ans = false;
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[0].size(); j++){
                if(board[i][j] == word[0]){
                    if(search(board, word, 1, i, j)) return true;
                }
            }
        }

        return false;
    }

    bool search(vector<vector<char>> &board, string word, int idx, int i, int j){
        board[i][j] = '#';

        if(idx == word.size()) return true;

        vector<int> dirs = {1,-1};
        bool ans = false;
        for(int d : dirs){
            if(i+d >=0 && i+d < board.size() && board[i+d][j] == word[idx])
                ans |= search(board, word, idx+1, i+d, j);
            if(ans) return ans;
            if(j+d >=0 && j+d < board[0].size() && board[i][j+d] == word[idx])
                ans|= search(board, word, idx+1, i, j+d);
            if(ans) return ans;
        }
        board[i][j] = word[idx-1];
        return ans;
    }
};