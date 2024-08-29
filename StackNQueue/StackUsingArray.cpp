class Stack {
    private:
        int st[10];
        int top = -1;
    public:
        void push(int x) {
            if(!isFull()) {
                st[++top] = x;
            }
        }
        bool isEmpty() {
            if(top == -1) {
                return true;
            }
            return false;
        }
        bool isFull() {
            if(top == 9) {
                return true;
            }
            return false;
        }
        void pop() {
            if(!isEmpty()) {
                st[top--];
            }
        }
        int top() {
            if(!isEmpty()) {
                return st[top];
            }
            return -1;
        }
        int size() {
            return top+1;
        }
};