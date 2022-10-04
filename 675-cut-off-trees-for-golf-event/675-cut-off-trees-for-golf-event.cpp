class Solution {
public:
    int dirs[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    
    int bfs(vector<vector<int>>& forest, int sx, int sy, int tx, int ty){
        if (sx == tx && sy == ty){
            return 0;
        }
        queue<pair<int, int>> q;
        int m = forest.size();
        int n = forest[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        q.emplace(sx,sy);
        visited[sx][sy] = true;
        int step = 0;
        while (!q.empty()){
            step++;
            int size = q.size();
            for (int i=0; i<size; i++){
                auto location = q.front();
                q.pop();
                for (int j=0; j<4; j++){
                    int x = location.first + dirs[j][0];
                    int y = location.second + dirs[j][1];
                    if (x >= 0 && x < m && y >= 0 && y < n){
                        if (!visited[x][y] && forest[x][y] > 0){
                            if (x == tx && y == ty){
                                return step;
                            }
                            visited[x][y] = true;
                            q.emplace(x, y);
                        }
                    }
                }
            }
        }
        return -1;
    }
    int cutOffTree(vector<vector<int>>& forest) {
        vector<pair<int, int>> tree;
        int m = forest.size();
        int n = forest[0].size();
        for (int i=0; i<m;i++){
            for (int j=0; j<n; j++){
                if (forest[i][j] > 1){
                    tree.emplace_back(i,j);
                }
            }
        }
        sort(tree.begin(), tree.end(), [&](const pair<int, int> & a, const pair<int, int> & b) {
            return forest[a.first][a.second] < forest[b.first][b.second];
        });
        int x = 0, y = 0, total = 0;
        for (int i=0; i<tree.size(); i++){
            int step = bfs(forest, x, y, tree[i].first, tree[i].second);
            if (step == -1) return -1;
            total += step;
            x = tree[i].first;
            y = tree[i].second;
        }
        return total;
    }
};