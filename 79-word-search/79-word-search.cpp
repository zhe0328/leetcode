class Solution {
public:
    static constexpr int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    bool backtrack(int i, int j, int m, int n, vector<vector<int>> & mark, vector<vector<char>>& board, string word){
        if (!word.length()) return true;
        for (auto direct : directions){
            int cur_i = i+direct[0];
            int cur_j = j+direct[1];
            if (cur_i >= 0 && cur_i < m && cur_j >= 0 && cur_j < n && board[cur_i][cur_j] == word[0]){
                if (mark[cur_i][cur_j] == 1) continue;
                mark[cur_i][cur_j] = 1;
                if (backtrack(cur_i, cur_j, m, n, mark, board, word.substr(1,word.length()-1))){
                    return true;
                }
                else {
                    mark[cur_i][cur_j] = 0;
                }
            }
        }
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m = board.size(), n = board[0].size();
        vector<vector<int>> mark(m, vector<int>(n,0));

        for (int i=0; i<m; i++){
            for (int j=0;j<n;j++){
                if (board[i][j] == word[0]){
                    mark[i][j] = 1;
                    if (backtrack(i, j, m, n, mark, board, word.substr(1,word.length()-1))) {
                        return true;
                    }
                    else {
                        mark[i][j] = 0;
                    }
                }
            }
        }
        return false;
    }
};