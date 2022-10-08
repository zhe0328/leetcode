class Solution {
public:
    const int directions[4][2] = {{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n));
        vector<vector<int>> visited(m, vector<int>(n));
        queue<pair<int,int>> q;
        for (int i=0; i<m; i++){
            for (int j=0; j<n; j++){
                if (mat[i][j] == 0){
                    res[i][j] = 0;
                    visited[i][j] = 1;
                    q.push({i,j});
                }
            }
        }
        while (!q.empty()){
            auto cur = q.front();
            q.pop();
            for (auto d:directions){
                int i = cur.first+d[0];
                int j = cur.second+d[1];
                if (i>=0 && i<m && j>=0 && j<n && !visited[i][j]){
                    res[i][j] = res[cur.first][cur.second]+1;
                    q.push({i,j});
                    visited[i][j] = 1;
                }
            }
        }
        return res;
    }
};