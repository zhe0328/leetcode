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
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* result = new ListNode(0);
        ListNode* cursor = result;
        if (l1 == nullptr){
            return l2;
        }
        else if (l2 == nullptr){
            return l1;
        }
        int carry = 0;
        while (l1 != nullptr || l2 != nullptr || carry){
            int l1_val = l1 == nullptr ? 0:l1->val;
            int l2_val = l2 == nullptr ? 0:l2->val;
            int cur = l1_val + l2_val + carry;
            carry = 0;
            if (cur >9) {
                carry = cur / 10;
                cur = cur % 10;
            }
            ListNode * tmp = new ListNode(cur);
            cursor->next = tmp;
            if (l1 != nullptr){
                l1 = l1->next;
            }
            if (l2 != nullptr){
                l2 = l2->next;
            }
            cursor = cursor->next;
        }
        return result->next;
    }
};