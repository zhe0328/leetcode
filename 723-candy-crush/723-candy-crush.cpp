class Solution {
public:
    vector<vector<int>> candyCrush(vector<vector<int>>& board) {
        int row = board.size();
        int col = board[0].size();
        bool flag = false;
        for (int i=0; i<row; i++){
            for (int j=0; j<col-2; j++){
                int value = abs(board[i][j]);
                if (value != 0 && value == abs(board[i][j+1]) && value == abs(board[i][j+2])){
                    flag = true;
                    board[i][j] = -value;
                    board[i][j+1] = -value;
                    board[i][j+2] = -value;
                }
            }
        }
        for (int i=0; i<row-2; i++){
            for (int j=0; j<col; j++){
                int value = abs(board[i][j]);
                if (value != 0 && value == abs(board[i+1][j]) && value == abs(board[i+2][j])){
                    flag = true;
                    board[i][j] = -value;
                    board[i+1][j] = -value;
                    board[i+2][j] = -value;
                }
            }
        }
        for (int j=0; j<col; j++){
            int idx = row-1;
            for (int i=row-1; i>=0; i--){
                if (board[i][j] > 0){
                    board[idx][j] = board[i][j];
                    --idx;
                }
            }
            while (idx >= 0){
                board[idx][j] = 0;
                --idx;
            }
        }
        return flag ? candyCrush(board) : board;
    }
};