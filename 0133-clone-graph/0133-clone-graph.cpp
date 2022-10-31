/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, unordered_map<Node*,Node*> & hashMap){
        vector<Node*> neighbours;
        Node* clone = new Node(node->val);
        hashMap[node] = clone;
        for (auto nodeNeighbor: node->neighbors){
            if (hashMap.find(nodeNeighbor) != hashMap.end()){
                neighbours.push_back(hashMap[nodeNeighbor]);
            }
            else {
                neighbours.push_back(dfs(nodeNeighbor, hashMap));
            }
        }
        clone->neighbors = neighbours;
        return clone;
    }
    Node* cloneGraph(Node* node) {
        unordered_map<Node*,Node*> hashMap;
        if (node == nullptr) return nullptr;
        if (!node->neighbors.size()) {
            Node * clone = new Node(node->val);
            return clone;
        }
        return dfs(node, hashMap);
    }
};