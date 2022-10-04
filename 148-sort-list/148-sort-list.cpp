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
    ListNode * mergeList(ListNode* l1, ListNode* l2){
        // merge sorted l1 an l2
        if (l1 == nullptr && l2 == nullptr) return nullptr;
        if (l1 == nullptr) return l2;
        if (l2 == nullptr) return l1;
        ListNode * pre = new ListNode(0);
        ListNode * cur = pre;
        while (l1 != nullptr && l2 != nullptr){
            if (l1->val < l2->val){
                cur->next = l1;
                l1 = l1->next;
            }
            else {
                cur->next = l2;
                l2 = l2->next;
            }
            cur = cur->next;
        }
        while (l1 != nullptr){
            cur->next = l1;
            l1 = l1->next;
            cur = cur->next;
        }
        while (l2 != nullptr){
            cur->next = l2;
            l2 = l2->next;
            cur = cur->next;
        }
        ListNode * res = pre->next;
        delete pre;
        return res;
    }
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) return head;
        ListNode* new_head = head;
        ListNode* tail = head;
        ListNode* temp;
        while (tail != nullptr && tail->next != nullptr){
            temp = head;
            head = head->next;
            tail = tail->next->next;
        }
        temp->next = nullptr;
        ListNode* l1 = sortList(new_head);
        ListNode* l2 = sortList(head);
        return mergeList(l1, l2);
    }
};