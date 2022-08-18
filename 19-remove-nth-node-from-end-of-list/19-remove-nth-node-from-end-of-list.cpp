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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* copy = new ListNode(0,head);
        int size = 0;
        while (head != nullptr) {
            size++;
            head = head->next;
        }
        int m = size-n;
        ListNode* cur = copy;
        while (m>0){
            cur = cur->next;
            m--;
        }
        cur->next = cur->next->next;
        // nextNode->next = nullptr;
        ListNode * ans = copy->next;
        delete copy;
        return ans;
    }
};