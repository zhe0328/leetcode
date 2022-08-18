class Solution {
public:
    bool compare(string substr, string needle){
        for (int i=0;i<substr.size();i++){
            if (substr[i] != needle[i]){
                return false;
            }
        }
        return true;
    }
    int strStr(string haystack, string needle) {
        int start = 0, idx = -1;
        while (start + needle.size() <= haystack.size()){
            string substr = haystack.substr(start, needle.size());
            if (compare(substr, needle)) {
                idx = start;
                break;
            }
            start++;
        }
        return idx;
    }
};