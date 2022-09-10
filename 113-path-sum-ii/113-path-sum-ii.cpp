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
    void dfs(vector<vector<int>> & res, vector<int> & cur, TreeNode* root, int targetSum) {
        if (root == nullptr) return;
        cur.push_back(root->val);
        targetSum -= root->val;
        if (root->left == nullptr && root->right == nullptr && !targetSum){
            res.push_back(cur);
        }
        dfs(res, cur, root->left, targetSum);
        dfs(res, cur, root->right, targetSum);
        cur.pop_back();
    }
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<vector<int>> res;
        vector<int> cur;
        dfs(res, cur, root, targetSum);
        return res;
    }
};