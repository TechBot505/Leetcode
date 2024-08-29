class Solution {
public:
    Node* copyRandomList(Node* head) {
        Node* iter = head;
        Node* front = head;
        while(iter) {
            front = iter->next;
            Node* copy = new Node(iter->val);
            copy->next = front;
            iter->next = copy;
            iter = front;
        }
        iter = head;
        while(iter) {
            if(iter->random) {
                iter->next->random = iter->random->next;
            }
            iter = iter->next->next;
        }
        iter = head;
        Node* pseudoHead = new Node(0);
        Node* copy = pseudoHead;
        while(iter) {
            front = iter->next->next;
            copy->next = iter->next;
            iter->next = front;
            copy = copy->next;
            iter = front;
        }
        return pseudoHead->next;
    }
};