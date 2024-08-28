class Solution {
public:
    ListNode* reverseList(ListNode* head) {
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(head) {
            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    ListNode* plusOne(ListNode* head) {
        head = reverseList(head);
        ListNode* temp = head;
        int carry = 1;
        while(temp) {
            int sum = temp->val + carry;
            carry = sum/10;
            temp->val = sum%10;
            temp = temp->next;
            sum = 0;
        }
        head = reverseList(head);
        if(carry) {
            ListNode* node = new ListNode(carry, head);
            return node;
        }
        return head;
    }
}