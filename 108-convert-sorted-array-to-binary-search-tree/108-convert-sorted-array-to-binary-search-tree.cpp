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
    TreeNode * buildBST(vector<int>& num, int start, int end){
        if (start>end) return nullptr;
        int rootIndex = (start+end)/2;
        TreeNode * root = new TreeNode(num[rootIndex]);
        root->left = buildBST(num, start, rootIndex-1);
        root->right = buildBST(num, rootIndex+1, end);
        return root;
    }
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return buildBST(nums, 0, nums.size()-1);
    }
};