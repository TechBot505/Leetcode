class Solution {
public:
    ListNode* deleteMiddle(ListNode* head) {
        if(head->next == NULL) return NULL;
        ListNode* slow = head, *fast = head, *temp = NULL;
        while(fast && fast->next) {
            temp = slow;
            fast = fast->next->next;
            slow = slow->next;
        }
        if(temp) {
            temp->next = slow->next;
            delete slow;
            return head;
        }
        return NULL;
    }
};