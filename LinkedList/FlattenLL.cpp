// Optimal
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* curr = head;
        Node* next1 = flatten(head->child);
        Node* next2 = flatten(head->next);
        if(next1) {
            curr->next = next1;
            next1->prev = curr;
            curr->child = nullptr;
            while(curr->next) curr = curr->next;
        }
        curr->next = next2;
        if(next2) next2->prev = curr;
        return head;
    }
};

// Using Stack
class Solution {
public:
    Node* flatten(Node* head) {
        if(!head) return head;
        Node* curr = head;
        stack<Node*> st;
        while(curr) {
            if(curr->child) {
                Node* node = curr->next;
                curr->next = curr->child;
                curr->child->prev = curr;
                curr->child = nullptr;
                if(node) {
                    st.push(node);
                }
            } else if(!curr->next && !st.empty()) {
                Node* node = st.top();
                st.pop();
                curr->next = node;
                node->prev = curr;
            }
            curr = curr->next;
        }
        return head;
    }
};