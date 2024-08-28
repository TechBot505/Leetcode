class Solution {
public:
    ListNode* removeElements(ListNode* head, int val) {
        if(head == NULL) return NULL;
        ListNode* dummy = new ListNode(0);
        dummy->next = head;
        ListNode* prev = dummy;
        while(prev && prev->next) {
            if(prev->next->val == val) {
                ListNode* temp = prev->next;
                prev->next = temp->next;
                delete temp;
            }
            else prev = prev->next;
        }
        return dummy->next;
    }
};