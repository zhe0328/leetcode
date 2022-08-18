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
    struct Status {
        int val;
        ListNode * ptr;
        bool operator < (const Status &rhs) const {
            return val > rhs.val;
        }    
    };
    priority_queue <Status> queue;
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        ListNode* res = new ListNode(0);
        ListNode* cur = res;
        for (auto list : lists) {
            if (list != nullptr){
                queue.push({list->val,list});
            }
        }
        while (!queue.empty()){
            Status status = queue.top();
            queue.pop();
            cur->next = status.ptr;
            cur = cur->next;
            if (status.ptr->next != nullptr) {
                queue.push({status.ptr->next->val, status.ptr->next});
            }

        }
        ListNode * ans = res->next;
        delete res;
        return ans;
    }
};
