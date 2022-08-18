class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        if (intervals.size()<=1) return intervals;
        vector<vector<int>> res;
        sort(intervals.begin(), intervals.end());
        int start = intervals[0][0], end = intervals[0][1];
        for (auto interval : intervals) {
            if (interval[0] <= end){
                end = max(end, interval[1]);
            }
            else {
                res.push_back({start, end});
                start = interval[0];
                end = interval[1];
            }
        }
        res.push_back({start, end});
        return res;
    }
};