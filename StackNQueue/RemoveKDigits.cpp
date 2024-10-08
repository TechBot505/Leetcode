class Solution {
public:
    string removeKdigits(string num, int k) {
        int n = num.size();
        if(k>=n) return "0";
        stack<char> st;
        for(char c : num) {
            while(!st.empty() && k>0 && c < st.top()) {
                st.pop();
                k--;
            }
            if(!st.empty() || c != '0') st.push(c);
        }
        while(k && !st.empty()) {
            st.pop();
            k--;
        }
        if(st.empty()) return "0";
        string ans = "";
        while(!st.empty()) {
            ans += st.top();
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};