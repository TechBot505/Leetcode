// Without Stack
class Solution {
public:
    int maxDepth(string s) {
        int count = 0;
        int maxDepth = 0;
        for(char c : s) {
            if(c == '(') {
                count++;
                maxDepth = max(maxDepth, count);
            }
            else if(c == ')') {
                count--;
            }
        }
        return maxDepth;
    }
};

// Stack
class Solution {
public:
    int maxDepth(string s) {
        stack<int> st;
        int maxDepth = 0;
        for(char c : s) {
            if(c == '(') {
                st.push(c);
                maxDepth = max(maxDepth, (int)st.size());
            }
            else if(c == ')') {
                st.pop();
            }
        }
        return maxDepth;
    }
};