class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        unordered_map<int,int> hashMap;
        unordered_set<int> stored;
        int res = 0;
        for (auto t:time){
            int modulus = t % 60;
            if (modulus <= 30 && stored.find(modulus) == stored.end()) {
                stored.insert(modulus);
            }
            if (hashMap.find(modulus) != hashMap.end()){
                ++hashMap[modulus];
            }
            else {
                hashMap[modulus]=1;
            }
        }
        for (auto modulus:stored){
            if (modulus != 30 && hashMap.find(60-modulus) != hashMap.end()){
                res += hashMap[modulus]*hashMap[60-modulus];
            }
            if (modulus == 0 || modulus == 30){
                res += 1ll*hashMap[modulus]*(hashMap[modulus]-1)/2;
            }
        }
        return res;
    }
};