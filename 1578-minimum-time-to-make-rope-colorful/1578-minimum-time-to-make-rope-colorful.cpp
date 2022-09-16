class Solution {
public:
    int minCost(string colors, vector<int>& neededTime) {
        int cur = 0, size = colors.size();
        int res = 0;
        while (cur < size){
            char ch = colors[cur];
            int max_value = 0;
            int sum = 0;
            while (cur < size && colors[cur] == ch){
                max_value = max(neededTime[cur], max_value);
                sum += neededTime[cur];
                cur++;
            }
            res += sum - max_value;
        }
        return res;
    }
};