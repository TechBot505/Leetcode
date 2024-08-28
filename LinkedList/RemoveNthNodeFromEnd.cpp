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

// Calculating Length and Deleting Node approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        if(head->next == nullptr) {
            if(n==1) return nullptr;
        }
        int length = 0;
        ListNode* temp = head;
        while(temp != nullptr) {
            length++;
            temp = temp->next;
        }
        temp = head;
        if(length == n) {
            head = head->next;
            temp->next = nullptr;
            delete temp;
            return head;
        }
        else {
            ListNode* prev = nullptr;
            for(int i=1; i<=length-n; i++) {
                prev = temp;
                temp = temp->next;
            }
            prev->next = temp->next;
            temp->next = nullptr;
            delete temp;
        }
        return head;
    }
};

// Two Pointer Approach
class Solution {
public:
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        ListNode* node = new ListNode(-1);
        node->next = head;
        ListNode* fast = node;
        for(int i=0; i<n; i++) {
            fast = fast->next;
        }
        ListNode* slow = node;
        while(fast->next != nullptr) {
            fast = fast->next;
            slow = slow->next;
        }
        ListNode* curr = slow->next;
        slow->next = curr->next;
        curr->next = nullptr;
        return node->next;
    }
};