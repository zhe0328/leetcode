class Solution {
public:
    int maxArea(vector<int>& height) {
        int start = 0, end = height.size()-1, max_amount = 0;
        while (start<end){
            int size = min(height[start],height[end])*(end-start);
            if (height[start] < height[end]) {
                start++;
            }
            else {
                end--;
            }
            max_amount = max(max_amount, size);
        }
        return max_amount;
    }
};