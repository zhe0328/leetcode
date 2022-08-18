class Solution {
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        if (n==0) return res;
        vector<vector<string>> total;
        total.push_back(res); // n=0
        res.push_back("()");
        total.push_back(res); // n=1
        for (int i=2;i<=n;i++){
            vector<string> cur;
            for (int k1=0;k1<=i-1;k1++){
                int k2=i-k1-1;
                vector<string> par1 = total[k1];
                vector<string> par2 = total[k2];
                if (!par1.size() && par2.size()) {
                    for (auto q : par2){
                        string temp = "()" + q;
                        cur.push_back(temp);
                    }
                }
                if (!par2.size() && par1.size()) {
                    for (auto p : par1){
                        string temp = "(" + p + ")";
                        cur.push_back(temp);
                    }
                }
                for (auto p : par1) {
                    for (auto q : par2){
                        string temp = "(" + p + ")" + q;
                        cur.push_back(temp);
                    }
                }
            }
            total.push_back(cur);
        }
        return total[n];
    }
};