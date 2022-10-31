class NumMatrix {
private:
    vector<vector<int>> preSum;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        preSum.resize(m);
        for (int i=0; i<m; i++){
            preSum[i].resize(n);
        }
        preSum[0][0] = matrix[0][0];
        for (int i=1; i<m; i++){
            preSum[i][0] = preSum[i-1][0] + matrix[i][0]; 
        }
        for (int j=1; j<n; j++){
            preSum[0][j] = preSum[0][j-1] + matrix[0][j]; 
        }
        for (int i=1; i<m; i++){
            for (int j=1; j<n; j++){
                preSum[i][j] = preSum[i][j-1] + preSum[i-1][j] - preSum[i-1][j-1] + matrix[i][j];
            }
        }
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        if (row1 == 0 && col1 == 0) {
            return preSum[row2][col2];
        }
        else if (row1 == 0){
            return preSum[row2][col2]-preSum[row2][col1-1];
        }
        else if (col1 == 0) {
            return preSum[row2][col2]-preSum[row1-1][col2];
        }
        return preSum[row2][col2]+preSum[row1-1][col1-1]-preSum[row1-1][col2]-preSum[row2][col1-1];
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */