class Solution {
public:
    string simplifyPath(string path) {
        string res;
        stack<string> stored;
        int left = -1, right = 0;
        if (path[path.size()-1] != '/'){
            path += '/';
        }
        int size = path.length();
        for (int i=0; i<size; i++){
            if (left == -1 && path[i] == '/'){
                left = i;
            }
            else if (path[i] == '/') {
                right = i;
                string temp = path.substr(left+1, right-left-1);
                if (temp == "..") {
                    if (!stored.empty()) {
                        stored.pop();
                    }
                }
                else if (temp != "" && temp != "."){
                    stored.push(temp);
                }
                left = right;
            }

        }
        while (!stored.empty()){
            string temp = stored.top();
            stored.pop();
            if (res == ""){
                res = temp;
            }
            else {
                res = temp + '/'+ res;
            }
        }
        res = '/' + res;
        return res;
    }
};