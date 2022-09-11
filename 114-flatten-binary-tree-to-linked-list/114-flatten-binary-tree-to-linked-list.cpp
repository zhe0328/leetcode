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
    TreeNode* findRightMost(TreeNode* root){
        //find root's right most leaf
        while (root->right != nullptr){
            root = root->right;
        }
        return root;
    }
    void flatten(TreeNode* root) {
        if (root == nullptr) return;
        TreeNode * cur = root;
        while (cur != nullptr){
            if (cur->left != nullptr){
                TreeNode * pre = findRightMost(cur->left);
                pre->right = cur->right;
                cur->right = cur->left;
                cur->left = nullptr;
            }
            cur = cur->right;
        }
    }
};