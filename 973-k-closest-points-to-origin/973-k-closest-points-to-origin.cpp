class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<int, vector<int>, greater<int>> q; // min heap
        unordered_map<int, vector<vector<int>>> hashMap;
        for (auto point:points){
            int i = point[0];
            int j = point[1];
            int dist2 = pow(i,2)+pow(j,2);
            hashMap[dist2].push_back({i,j});
            q.push(dist2);
        }
        int cur = 0;
        vector<vector<int>> res;
        while (cur < k){
            auto dist2 = q.top();
            q.pop();
            for (auto point: hashMap[dist2]){
                res.push_back(point);
                ++cur;
            }
        }
        return res;
    }
};