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
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder) {
        if (!inorder.size()) return nullptr;
        TreeNode * root = new TreeNode(postorder[postorder.size()-1]);
        stack<TreeNode*> stk;
        stk.push(root);
        int inorderIndex = postorder.size()-1;
        for (int i=inorderIndex-1; i>=0; i--){
            int postOrderVal = postorder[i];
            auto node = stk.top();
            if (node->val != inorder[inorderIndex]){
                node->right = new TreeNode(postOrderVal);
                stk.push(node->right);
            }
            else {
                while (!stk.empty() && stk.top()->val == inorder[inorderIndex]){
                    node = stk.top();
                    stk.pop();
                    inorderIndex--;
                }
                node->left = new TreeNode(postOrderVal);
                stk.push(node->left);
            }
        }
        return root;
    }
};