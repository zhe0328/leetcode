/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    void recoverTree(TreeNode* root) {
        TreeNode* pre = nullptr, * x = nullptr, * y = nullptr;
        stack<TreeNode*> s;
        while (!s.empty() || root != nullptr){
            while (root != nullptr){
                s.push(root);
                root=root->left;
            }
            root = s.top();
            s.pop();
            if (pre != nullptr && root->val < pre->val){
                y = root;
                if (x == nullptr) {
                    x = pre;
                }
                else {
                    break;
                }
            }
            pre = root;
            root = root->right;
        }
        swap(x->val, y->val);
    }
};


