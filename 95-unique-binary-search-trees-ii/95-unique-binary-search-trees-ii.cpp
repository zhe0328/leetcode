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
private:

public:
    vector<TreeNode*> getTrees(int start, int end){
        if (start>end) return {nullptr};
        vector<TreeNode*> allTrees;
        for (int i = start; i <= end; i++){
            vector<TreeNode*> leftTrees = getTrees(start, i-1);
            vector<TreeNode*> rightTrees = getTrees(i+1, end);
            for (auto left: leftTrees) {
                for (auto right: rightTrees){
                    TreeNode * cur = new TreeNode(i);
                    cur->left = left;
                    cur->right = right;
                    allTrees.emplace_back(cur);
                }
            }
        }
        return allTrees;
    }

    vector<TreeNode*> generateTrees(int n) {
        return getTrees(1,n);
    }
};