class UnionFind {
public:
    vector<int> pre;
    vector<int> size;
    int setCount;

    UnionFind(int n) {
        size.resize(n, 1);
        pre.resize(n);
        setCount = n;
        for (int i=0; i<n; i++){
            pre[i] = i;
        }
    }
    int find(int x){
        if (x != pre[x]){
            pre[x] = find(pre[x]);
        }
        return pre[x];
    }
    bool unite(int x, int y){
        int rootx = find(x);
        int rooty = find(y);
        if (rootx == rooty) return false;
        if (size[rootx] < size[rooty]){
            swap(rootx,rooty);
        }
        pre[rooty] = rootx;
        size[rootx] += size[rooty];
        --setCount;
        return true;
    }
    bool connected(int x, int y){
        return find(x) == find(y);
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        if (connections.size() < n-1) return -1;
        UnionFind uf(n);
        for (auto connection:connections){
            uf.unite(connection[0], connection[1]);
        }
        return uf.setCount-1;
    }
};