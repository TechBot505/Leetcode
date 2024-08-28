class Solution {
public:
    ListNode *detectCycle(ListNode *head) {
        if(head == NULL) return NULL;
        ListNode* p = head, *q = head;
        while(q->next && q->next->next) {
            p = p->next;
            q = q->next->next;
            if(p == q) {
                while(head != p) {
                    head = head->next;
                    p = p->next;
                }
                return head;
            }
        }
        return NULL;
    }
};