class Solution {
public:
    void backtrack(vector<string> & res, string cur, int n, int * visited, int k){
        if (cur.size() == n){
            res.push_back(cur);
            return;
        }
        if (res.size() == k) return;
        for (int i=0; i<n; i++){
            if (visited[i] == 1) continue;
            visited[i] = 1;
            cur += i + 1 + '0';
            backtrack(res, cur, n, visited, k);
            visited[i] = 0;
            cur.pop_back();
        }  

    }
    string getPermutation(int n, int k) {
        vector<string> res;
        string cur;
        int visited[n];
        backtrack(res, cur, n, visited, k);
        return res[k-1];
    }
};