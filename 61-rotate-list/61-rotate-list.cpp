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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) {
            return head;
        }
        ListNode * tail = head;
        ListNode * cur = head;
        int n = 1;
        while (tail->next != nullptr) {
            tail= tail->next;
            n++;
        }
        int m = n - (k % n);
        for (int i = 1; i<m;i++) {
            cur = cur->next;
        }
        tail->next = head;
        ListNode * new_head = cur->next;
        cur->next = nullptr;
        return new_head;

    }
};