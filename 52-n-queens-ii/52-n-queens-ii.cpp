class Solution {
public:
    int totalNQueens(int n) {
        int res = 0;
        vector<int> queens(n,-1); // eg: 0:2 0th row's Q is at 2th col
        unordered_set<int> columns;
        unordered_set<int> diag1;
        unordered_set<int> diag2;
        backtrack(res, queens, n, 0, columns, diag1, diag2);
        return res;
    }

    void backtrack(int & res, vector<int> & queens, int n, int row,unordered_set<int> & columns, unordered_set<int> & diag1, unordered_set<int> & diag2) {
        if (row == n){
            res++;
            return;
        }
        for (int i=0; i<n; i++){
            if (columns.find(i) != columns.end()) {
                continue;
            }
            int d1 = row - i;
            if (diag1.find(d1) != diag1.end()) {
                continue;
            }
            int d2 = row + i;
            if (diag2.find(d2) != diag2.end()) {
                continue;
            }
            columns.insert(i);
            diag1.insert(d1);
            diag2.insert(d2);
            queens[row] = i;
            backtrack(res, queens, n, row + 1, columns, diag1, diag2);
            queens[row] = -1;
            columns.erase(i);
            diag1.erase(d1);
            diag2.erase(d2);
        }

    }
};
