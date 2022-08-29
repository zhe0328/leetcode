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
    bool isValidBST(TreeNode* root) {
        if (root == nullptr) return true;
        vector<TreeNode*> stored;
        stack<TreeNode*>s;
        while (root != nullptr || !s.empty()){
            while (root != nullptr){
                s.push(root);
                root = root->left;
            }
            root = s.top();
            s.pop();
            if (stored.size()>0) {
                TreeNode* pre = stored[stored.size()-1];
                if (pre->val >= root->val) return false;
            }
            stored.push_back(root);
            root = root->right;
        }
        return true;
    }
};