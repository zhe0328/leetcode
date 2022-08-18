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
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
        ListNode* merged = new ListNode(0);
        ListNode* start = merged;
        while (list1!=nullptr && list2!=nullptr) {
            if (list1->val < list2->val){
                start->next = new ListNode(list1->val);
                list1=list1->next;
            }
            else {
                start->next = new ListNode(list2->val);
                list2=list2->next;
            }
            start = start->next;
        }
        while (list1!=nullptr){
            start->next = new ListNode(list1->val);
            list1=list1->next;
            start = start->next;
        }
        while (list2!=nullptr){
            start->next = new ListNode(list2->val);
            list2=list2->next;
            start = start->next;
        }
        ListNode * res = merged->next;
        delete merged;
        return res;
    }
};