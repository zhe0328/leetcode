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
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        if (left == right) return head;
        ListNode * cur = head;
        ListNode * left_node, * right_node;
        ListNode * pre_left = nullptr, * after_right = nullptr;
        ListNode * pre = nullptr;
        int n = 1;
        while (cur != nullptr){
            if (n>right+1) {
                break;
            }
            else if (n == left-1){
                pre_left = cur;
            }
            else if (n == right+1){
                after_right = cur;
            }
            if (n == left){
                left_node = cur;
            }
            if (n == right){
                right_node = cur;
            }
            if (n>left && n<=right){
                ListNode * new_cur = cur->next;
                cur->next = pre;
                if (n == left+1) pre->next = nullptr;
                pre = cur;
                cur = new_cur;
            }
            else {
                pre = cur;
                cur = cur->next;
            }
            n++;
        }
        if (pre_left != nullptr){
            pre_left->next = right_node;
        }
        else {
            head = right_node;
        }
        if (after_right != nullptr){
            left_node->next = after_right;
        }
        if (right-left == 1){
            right_node->next = left_node;
        }
        return head;
    }
};