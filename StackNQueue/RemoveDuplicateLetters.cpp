class Solution {
public:
    string removeDuplicateLetters(string s) {
        int n = s.size();
        stack<char> st;
        unordered_set<char> seen;
        unordered_map<char, int> last;
        for(int i=0; i<n; i++) {
            last[s[i]] = i;
        }
        for(int i=0; i<n; i++) {
            char c = s[i];
            if(seen.find(c) == seen.end()) {
                while(!st.empty() && c < st.top() && i < last[st.top()]) {
                    seen.erase(st.top());
                    st.pop();
                }
                seen.insert(c);
                st.push(c);
            }
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