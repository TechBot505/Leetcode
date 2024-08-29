class MyQueue {
public:
    stack<int> st1;
    stack<int> st2;
    MyQueue() {
    }
    
    void push(int x) {
        while(!st2.empty()){
            st1.push(st2.top());
            st2.pop();
        }
        st1.push(x);
    }
    
    int pop() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        int a=st2.top();
        st2.pop();
        return a;
    }
    
    int peek() {
        while(!st1.empty()){
            st2.push(st1.top());
            st1.pop();
        }
        return st2.top();
    }
    
    bool empty() {
        return st1.empty()&&st2.empty();
    }
};