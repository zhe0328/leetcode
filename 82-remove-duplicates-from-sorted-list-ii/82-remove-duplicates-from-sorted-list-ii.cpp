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
    ListNode* deleteDuplicates(ListNode* head) {
        if (head == nullptr) {
            return head;
        }
        else if (head->next == nullptr){
            return head;
        }
        ListNode * dummy = new ListNode();
        dummy->next = head;
        ListNode * cur = dummy;
        while (cur->next && cur->next->next){
            if (cur->next->val == cur->next->next->val){
                int deleted = cur->next->val;
                while (cur->next && cur->next->val == deleted) {
                    ListNode * temp = cur->next;
                    cur->next = cur->next->next;
                    delete temp;
                }
            }
            else {
                cur = cur->next;
            }
        }
        ListNode * new_head = dummy->next;
        delete dummy;
        return new_head;
    }
};