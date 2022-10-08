class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        priority_queue<pair<int,int>> q; // max heap <dist, idx>
        for (int i=0; i<k; i++){
            int m = points[i][0];
            int n = points[i][1];
            int dist2 = pow(m,2)+pow(n,2);
            q.push({dist2, i});
        }
        for (int i=k; i<points.size(); i++){
            int m = points[i][0];
            int n = points[i][1];
            int dist2 = pow(m,2)+pow(n,2);
            if (q.top().first > dist2){
                q.pop();
                q.push({dist2, i});
            }
        }
        vector<vector<int>> res;
        while (!q.empty()){
            auto idx = q.top().second;
            q.pop();
            res.push_back(points[idx]);
        }
        return res;
    }
};