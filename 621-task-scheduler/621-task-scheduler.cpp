class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        int size = tasks.size();
        if (n==0 || size==1) return size;
        unordered_map<char,int> hashMap;
        int maxCount = 0;
        for (auto task:tasks){
            if (hashMap.find(task) == hashMap.end()){
                hashMap[task] = 1;
            }
            else {
                ++hashMap[task];
            }
            maxCount = max(maxCount, hashMap[task]);
        }
        int c = 0;
        for (auto & v: hashMap){
            if (v.second == maxCount){
                ++c;
            }
        }
        return max((maxCount-1)*(n+1)+c, size);
    }
};