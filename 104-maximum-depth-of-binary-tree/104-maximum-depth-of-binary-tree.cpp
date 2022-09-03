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
    int maxDepth(TreeNode* root) {
        // dfs
        if (root == nullptr) return 0;
        stack<pair<TreeNode*,int>> stk;
        stk.push({root,1});
        int length = 1;
        while (!stk.empty()){
            TreeNode* node = stk.top().first;
            int cur = stk.top().second;
            stk.pop();
            if (node->left != nullptr){
                stk.push({node->left, cur+1});
            }
            if (node->right != nullptr){
                stk.push({node->right, cur+1});
            }
            length = cur > length ? cur : length;
        }
        return length;
    }
};