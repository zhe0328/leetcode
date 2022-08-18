class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int rows[9][9]; // rows[i][k]=1: i-th row has number k
        int cols[9][9]; // cols[j][k]=1: j-th col has number k
        int boxes[3][3][9]; // boxes[i][j][k]=1: (i, j)-th box has number k
        memset(rows, 0, sizeof(rows));
        memset(cols, 0, sizeof(cols));
        memset(boxes, 0, sizeof(boxes));
        
        for (int i=0;i<9;i++){
            for (int j=0;j<9;j++){
                char c = board[i][j];
                if (c != '.'){ // is number
                    int num = c - '0' - 1;
                    if (rows[i][num] == 0 && cols[j][num] == 0 && boxes[i/3][j/3][num] == 0) {
                        rows[i][num] = 1;
                        cols[j][num] = 1;
                        boxes[i/3][j/3][num] = 1;
                    }
                    else {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};