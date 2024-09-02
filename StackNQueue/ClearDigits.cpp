class Solution {
public:
    string clearDigits(string s) {
        stack<char> st;
        for(auto it : s) {
            if(!st.empty() && it >= '0' && it <= '9') st.pop();
            else st.push(it);
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