class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minPrice = INT_MAX;
        int res = 0;
        for (int i=0; i<prices.size(); i++){
            if (prices[i] < minPrice){
                minPrice = prices[i];
            }
            if (prices[i]-minPrice > res){
                res = prices[i]-minPrice;
            } 
        }
        return res;
    }
};