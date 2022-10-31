class Solution {
public:
    void dfs(vector<vector<char>> & grid, int row, int col, vector<vector<int>> & visited){
        if (visited[row][col] == 1) return;
        visited[row][col] = 1;
        // grid[row][col] = 0;
        int m = grid.size();
        int n = grid[0].size();
        if (row>0 && grid[row-1][col] == '1') dfs(grid, row-1, col, visited);
        if (row+1<m && grid[row+1][col] == '1') dfs(grid, row+1, col, visited);
        if (col>0 && grid[row][col-1] == '1') dfs(grid, row, col-1, visited);
        if (col+1<n && grid[row][col+1] == '1') dfs(grid, row, col+1, visited);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n=grid[0].size();
        vector<vector<int>> visited(m, vector<int>(n,0));
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == '1' && visited[i][j] == 0){
                    ++ans;
                    dfs(grid,i,j, visited);
                }
            }
        }
        return ans;
    }
};