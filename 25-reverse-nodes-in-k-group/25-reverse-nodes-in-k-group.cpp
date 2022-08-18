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
    pair<ListNode*,ListNode*> reverseNode(ListNode* head, ListNode* tail){
        ListNode* prev = tail->next;
        ListNode* p = head;
        while (prev != tail) {
            ListNode* next = p->next;
            p->next = prev;
            prev = p;
            p = next;
        }
        return {tail, head};
    }
    ListNode* reverseKGroup(ListNode* head, int k) {
        ListNode* cur = new ListNode(0);
        cur->next = head;
        ListNode* prev = cur;
        while (head != nullptr){
            ListNode * tail = prev;
            for (int i = 0; i < k; i++) {
                tail = tail->next;
                if (tail == nullptr){ // not enough
                    ListNode * res = cur->next;
                    delete cur;
                    return res;
                }
            }
            ListNode * next = tail->next;
            pair<ListNode*, ListNode*> result = reverseNode(head, tail);
            head = result.first;
            tail = result.second;
            prev->next = head;
            tail->next = next;
            prev = tail;
            head = next;
        }
        ListNode * res = cur->next;
        delete cur;
        return res;
    }
};