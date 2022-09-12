/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        // BFS
        if (root == nullptr) return root;
        queue<Node*> q;
        q.push(root);
        while (!q.empty()){
            int size = q.size();
            Node* pre_node = nullptr;
            for (int i=0; i<size; i++){
                auto node = q.front();
                if (pre_node != nullptr){
                    pre_node->next = node;
                }
                pre_node = node;
                q.pop();
                if (node->left != nullptr) {
                    q.push(node->left);
                }
                 if (node->right != nullptr) {
                    q.push(node->right);
                }
            }
        }
        return root;
    }
};