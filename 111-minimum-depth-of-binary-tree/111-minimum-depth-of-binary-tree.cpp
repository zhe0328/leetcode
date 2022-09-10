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
    int minDepth(TreeNode* root) {
        if (root == nullptr) return 0;
        int minDepth = INT_MAX;
        stack<pair<TreeNode*, int>> stk;
        stk.push({root,1});
        while (!stk.empty()){
            auto cur = stk.top();
            stk.pop();
            TreeNode* node = cur.first;
            int depth = cur.second;
            if (node->left == nullptr && node->right == nullptr){
                if (cur.second < minDepth){
                    minDepth = depth;
                }
            }
            if (node->left != nullptr && depth < minDepth) {
                stk.push({node->left, depth+1});
            }
            if (node->right != nullptr && depth < minDepth) {
                stk.push({node->right, depth+1});
            }
        }
        return minDepth;
    }
};