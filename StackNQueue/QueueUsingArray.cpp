class Queue {
    private:
        int q[10];
        int front = -1;
        int rear = -1;
    public:
        bool isFull() {
            if(rear == 9) {
                return true;
            }
            return false;
        }
        bool isEmpty() {
            if(front == -1 && rear == -1) {
                return true;
            }
            return false;
        }
        void enqueue(int x) {
            if(!isFull()) {
                if(front == -1) {
                    front++;
                }
                q[++rear] = x;
            }
        }
        void dequeue() {
            if(!isEmpty()) {
                if(front == rear) {
                    front = rear = -1;
                } else {
                    front++;
                }
            }
        }
        int top() {
            if(!isEmpty()) {
                return q[front];
            }
            return -1;
        }
        int size() {
            return rear-front+1;
        }
};