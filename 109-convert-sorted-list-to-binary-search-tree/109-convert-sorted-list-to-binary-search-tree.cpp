/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
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
    TreeNode * buildTree(vector<int> values, int start, int end){
        if (start > end) return nullptr;
        int mid = (end-start)/2+start;
        TreeNode * root = new TreeNode(values[mid]);
        root->left = buildTree(values, start, mid-1);
        root->right = buildTree(values, mid+1, end);
        return root;
    }
    TreeNode* sortedListToBST(ListNode* head) {
        if (head == nullptr) return nullptr;
        vector<int> values;
        while (head != nullptr){
            values.push_back(head->val);
            head = head->next;
        }
        return buildTree(values, 0, values.size()-1);
    }
};