class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>> res(n, vector<int>(n, 0));
        int x = 0, y = 0;
        int loop = n/2, mid = n/2, count = 1, offset = 1;
        int i, j;
        while (loop){
            i = x;
            j = y;

            for (j = y; j < n-offset; j++){
                res[x][j] = count++;
            }
            for (i = x; i < n-offset; i++){
                res[i][j] = count++;
            }
            for (; j>y;j--){
                res[i][j] = count++;
            }
            for (; i>x;i--){
                res[i][j] = count++;
            }
            x++;
            y++;
            offset++;
            loop--;
        }
        if (n % 2){
            res[mid][mid] = count;
        }
        return res;
    }
};