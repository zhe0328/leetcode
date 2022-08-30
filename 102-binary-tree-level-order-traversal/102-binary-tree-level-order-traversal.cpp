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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int level = 0;
        vector<int> preLevel;
        while (!q.empty()){
            pair<TreeNode*, int> cur = q.front();
            if (level == cur.second){
                preLevel.push_back(cur.first->val);
                q.pop();
                if (cur.first->left != nullptr){
                    q.push({cur.first->left, cur.second+1});
                }
                if (cur.first->right != nullptr){
                    q.push({cur.first->right, cur.second+1});
                }
            }
            else {
                level++;
                result.push_back(preLevel);
                preLevel.clear();
            }
        }
        result.push_back(preLevel);
        return result;
    }
};