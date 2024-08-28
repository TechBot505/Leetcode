class Solution {
public:
    ListNode* reverseBetween(ListNode* head, int left, int right) {
        ListNode* dummy = new ListNode(-1);
        dummy->next = head;
        ListNode* leftPrev = dummy;
        ListNode* curr = head;
        for(int i=1; i<left; i++) {
            leftPrev = curr;
            curr = curr->next;
        }
        ListNode* prev = nullptr;
        for(int i=left; i<=right; i++) {
            ListNode* temp = curr->next;
            curr->next = prev;
            prev = curr;
            curr = temp;
        }
        leftPrev->next->next = curr;
        leftPrev->next = prev;
        return dummy->next;
    }
};