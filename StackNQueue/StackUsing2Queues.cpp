class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int top = q1.front();
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return top;
    }
    
    int top() {
        while(q1.size()>1) {
            q2.push(q1.front());
            q1.pop();
        }
        int topE = q1.front();
        q2.push(topE);
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return topE;
    }
    
    bool empty() {
        return q1.empty();
    }
};