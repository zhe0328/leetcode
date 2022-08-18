class Solution {
public:
    int romanToInt(string s) {
        unordered_map<string, int> romanInt = {
            {"I", 1}, {"V", 5}, {"X", 10}, {"L", 50}, {"C", 100}, {"D", 500}, 
            {"M", 1000}, {"IV", 4}, {"IX", 9}, {"XL", 40}, {"XC", 90}, 
            {"CD", 400}, {"CM", 900},  
        };
        int res = 0;
        string temp;
        int i = 0;
        while (i < s.size()){
            if ((s[i] == 'I' || s[i] == 'X' || s[i] == 'C') && i+1 < s.size() && romanInt.find(s.substr(i,2)) != romanInt.end()){
                res += romanInt[s.substr(i,2)];
                i++;
            }
            else {
                temp = s[i];
                res += romanInt[temp];
            }
            i++;
        }
        return res;
    }
};