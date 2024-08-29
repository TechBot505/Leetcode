class Solution {
    ListNode* mergelist(ListNode* l1, ListNode* l2) {
        ListNode* dummy = new ListNode(0);
        ListNode* curr = dummy;
        while(l1 && l2) {
            if(l1->val < l2->val) {
                curr->next = l1;
                l1 = l1->next;
            }
            else {
                curr->next = l2;
                l2 = l2->next;
            }
            curr = curr->next;
        }
        if(l1) {
            curr->next = l1;
        }
        else if(l2) {
            curr->next = l2;
        }
        return dummy->next;
    }
public:
    ListNode* sortList(ListNode* head) {
        if(!head || !head->next) return head;
        ListNode* temp = NULL;
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast && fast->next) {
            temp = slow;
            slow = slow->next;
            fast = fast->next->next;
        }
        temp->next = NULL;
        ListNode* l1 = sortList(head);
        ListNode* l2 = sortList(slow);
        return mergelist(l1, l2);
    }
};