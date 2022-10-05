class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> hashMap;
        vector<string> res;
        for (auto str:cpdomains){
            int idx = str.find(" ");
            int time = stoi(str.substr(0, idx));
            string domain = str.substr(idx+1,str.size()-idx-1);
            while (domain.find('.') !=string::npos){
                if (hashMap.find(domain) == hashMap.end()){
                    hashMap[domain] = time;
                }
                else {
                    hashMap[domain] += time;
                }
                int dotIdx = domain.find('.');
                domain = domain.substr(dotIdx+1, domain.size()-dotIdx-1);
            }
            if (hashMap.find(domain) == hashMap.end()){
                hashMap[domain] = time;
            }
            else {
                hashMap[domain] += time;
            }
        }
        for (auto &v:hashMap){
            string cur = to_string(v.second) +" "+ v.first;
            res.push_back(cur);
        }
        return res;
    }
};