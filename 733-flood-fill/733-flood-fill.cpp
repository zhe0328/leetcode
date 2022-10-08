class Solution {
public:
    const int directions[4][2]={{0,1}, {0,-1}, {1,0}, {-1,0}};
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        // dfs
        int curColor = image[sr][sc];
        if (curColor == color) return image;
        int m = image.size();
        int n = image[0].size();
        stack<pair<int, int>> stk;
        stk.push({sr, sc});
        while (!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            if (image[cur.first][cur.second] == curColor){
                image[cur.first][cur.second] = color;
            }
            for (auto d:directions){
                int i = cur.first+d[0];
                int j = cur.second+d[1];
                if (i >= 0 && i < m && j >= 0 && j < n && image[i][j] == curColor){
                    stk.push({i,j});
                }
            }
        }
        return image;
    }
};