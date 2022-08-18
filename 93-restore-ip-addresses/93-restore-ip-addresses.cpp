class Solution {
private:
    static constexpr int SEG_COUNT = 4;
private:
    vector<string> res;
    vector<int> segments;
public:
    void backtracking(string s, int cur, int segID){
        if (segID == SEG_COUNT){
            if (cur == s.size()){
                string temp;
                for (int i=0; i<SEG_COUNT; i++){
                    temp += to_string(segments[i]);
                    if (i != SEG_COUNT-1) temp += '.';
                }
                res.push_back(temp);
            }
            return;
        }
        if (cur == s.size()) return; //no valid IP
        if (s[cur] == '0'){
            segments[segID] = 0;
            backtracking(s, cur+1, segID+1);
        }
        int addr = 0;
        for (int end = cur; end<s.size(); end++){
            addr = addr*10+(s[end]-'0');
            if (addr>0 && addr<=0xFF){
                segments[segID] = addr;
                backtracking(s, end+1, segID+1);
            }
            else {
                break;
            }
        }
    }
    vector<string> restoreIpAddresses(string s) {
        segments.resize(SEG_COUNT);
        backtracking(s, 0, 0);
        return res;
    }
};