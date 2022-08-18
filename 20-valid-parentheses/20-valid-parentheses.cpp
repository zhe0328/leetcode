class Solution {
public:
    bool isValid(string s) {
        stack<char> left;
        if (s.size()<2) return false; 
        for (auto c : s){
            if (c=='(' || c== '[' || c=='{'){
                left.push(c);
            }
            else {
                if (!left.empty()){
                    char cur = left.top();
                    left.pop();
                    if ((c==')' && cur=='(') || (c==']' && cur=='[')  || (c=='}' && cur=='{')) {
                        continue;
                    }
                }
                return false;
            }
        }
        if (left.empty()){
            return true;
        }
        else {
            return false;
        }
    }
};