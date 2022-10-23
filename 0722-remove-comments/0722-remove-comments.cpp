class Solution {
public:
    vector<string> removeComments(vector<string>& source) {
        vector<string> res;
        string build;
        bool block = false;
        for (auto str:source){
            for (int i=0; i<str.size(); i++){
                string two = str.substr(i, 2);
                if (!block){
                    if (two == "//") {
                        break;
                    }
                    else if (two == "/*"){
                        block = true;
                        i++;
                    }
                    else {
                        build.push_back(str[i]);
                    }
                }
                else if (two == "*/"){
                    block = false;
                    i++;
                }
            }
            if (!block && build.size()){
                res.push_back(build);
                build.clear();
            }
        }
        return res;
    }
};
