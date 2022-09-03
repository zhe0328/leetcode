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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        if (root == nullptr) return {};
        vector<vector<int>> res;
        queue<TreeNode*> q;
        int flag = 0;
        q.push(root);
        while (!q.empty()) {
            vector<int> cur;
            int size = q.size();
            for (int i=0; i<size; i++){
                TreeNode* node=q.front();
                q.pop();
                cur.emplace_back(node->val);
                if(node->left){
                q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            if (flag % 2 == 0){
                res.emplace_back(cur);
            }
            else {
                reverse(cur.begin(), cur.end());
                res.emplace_back(cur);
            }
            flag++;
        }
        return res;
    }
};