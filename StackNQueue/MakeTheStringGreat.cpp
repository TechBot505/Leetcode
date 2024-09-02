class Solution {
public:
    string makeGood(string s) {
        stack<char> st;
        for(char c : s) {
            if(!st.empty() && c != st.top() && (tolower(c) == st.top() || c == tolower(st.top()))) st.pop();
            else st.push(c);
        }
        string res = "";
        while(!st.empty()) {
            res += st.top();
            st.pop();
        }
        reverse(res.begin(), res.end());
        return res;
    }
};