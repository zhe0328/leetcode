class Solution {
public:
    void dfs(vector<vector<char>> & grid, int row, int col){
        grid[row][col] = 0;
        int m = grid.size();
        int n = grid[0].size();
        if (row>0 && grid[row-1][col] == '1') dfs(grid, row-1, col);
        if (row+1<m && grid[row+1][col] == '1') dfs(grid, row+1, col);
        if (col>0 && grid[row][col-1] == '1') dfs(grid, row, col-1);
        if (col+1<n && grid[row][col+1] == '1') dfs(grid, row, col+1);
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans = 0;
        int m = grid.size(), n=grid[0].size();
        for (int i=0;i<m;i++){
            for (int j=0;j<n;j++){
                if (grid[i][j] == '1'){
                    ++ans;
                    dfs(grid,i,j);
                }
            }
        }
        return ans;
    }
};