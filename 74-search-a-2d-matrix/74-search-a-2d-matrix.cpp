class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int low = 0, high = m*n-1;
        while (low <= high){
            int mid = (high-low)/2+low;
            int x = matrix[mid/n][mid%n];
            if (x == target){
                return true;
            }
            else if (x < target){
                low = mid+1;
            }
            else {
                high = mid-1;
            }
        }
        return false;
    }
};