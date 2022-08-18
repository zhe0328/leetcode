class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        int m = matrix.size();
        if (m == 0) return 0;
        int n = matrix[0].size();
        int left[m][n];
        memset(left, 0, sizeof(left));
        
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (matrix[i][j] == '1'){
                    left[i][j] = (j==0) ? 1 : left[i][j-1] + 1;
                }
                cout << left[i][j] << endl;
            }
        }
        int ret = 0;
        for (int j=0; j<n; j++){
            int up[m], down[m];
            stack<int> stk;
            for (int i=0; i<m; i++){
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]){
                    stk.pop();
                }
                up[i] = stk.empty() ? -1 : stk.top();
                stk.push(i);
            }

            stk = stack<int>();
            for (int i=m-1; i>=0; i--){
                while (!stk.empty() && left[stk.top()][j] >= left[i][j]){
                    stk.pop();
                }
                down[i] = stk.empty() ? m : stk.top();
                stk.push(i);
            }
            for (int i=0; i<m; i++) {
                int height = down[i] - up[i] - 1;
                int area = height * left[i][j];
                ret = max(ret, area);
            }
        }
        return ret;
    }
};