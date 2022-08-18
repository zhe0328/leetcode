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
class Solution {
public:
    ListNode* swapPairs(ListNode* head) {
        if (head == nullptr) return head;
        ListNode* left = head;
        ListNode* before_left = nullptr;
        ListNode* right = head->next;
        while (left != nullptr && right != nullptr){
            left->next = right->next;
            right->next = left;
            if (before_left!=nullptr){
                before_left->next = right;
            }
            else {
                head = right;
            }
            before_left = left;
            left = left->next;
            right = (left != nullptr) ? left->next : nullptr;
        }
        return head;
    }
};