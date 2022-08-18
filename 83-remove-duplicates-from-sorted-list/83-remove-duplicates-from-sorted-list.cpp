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
        ListNode * cur = head->next;
        ListNode * before = head;
        while (cur != nullptr){
            if (cur->val == before->val) {
                before->next = cur->next;
                ListNode * temp = cur;
                cur = cur->next;
                delete temp;
            }
            else {
                cur = cur->next;
                before = before->next;
            }
        }
        return head;
    }
};