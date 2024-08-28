class Solution {
public:
    ListNode* deleteDuplicates(ListNode* head) {
        if(head == NULL) return head;
        ListNode* p = head;
        while(p->next) {
            if(p->val == p->next->val) {
                ListNode* q = p->next;
                p->next = q->next;
                delete q;
            }
            else p = p->next;
        }
        return head;
    }
};