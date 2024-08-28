class Solution {
public:
    ListNode* rotateRight(ListNode* head, int k) {
        if(!head || !head->next || k==0) return head;
        int len = 1;
        ListNode* temp = head;
        while(temp->next != nullptr) {
            temp = temp->next;
            len++;
        }
        k = k%len;
        if(k==0) {
            return head;
        }
        else temp->next = head;
        for(int i=1; i<=len-k; i++) {
            temp = temp->next;
        }
        head = temp->next;
        temp->next = nullptr;
        return head;
    }
};