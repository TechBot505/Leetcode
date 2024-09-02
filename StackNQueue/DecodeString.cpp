class Solution {
public:
    string decodeString(string s) {
        int n = s.size();
        stack<int> cnt;
        stack<string> st;
        string ans = "";
        string temp = "";
        int num = 0;
        for(int i=0; i<n; i++) {
            if(isdigit(s[i])) {
                num = num * 10 + (s[i] - '0');
            }
            else if(s[i] == '[') {
                cnt.push(num);
                st.push(ans);
                num = 0;
                ans = "";
            }
            else if(s[i] == ']') {
                temp = ans;
                for(int j=1; j<cnt.top(); j++) {
                    ans = ans + temp;
                }
                cnt.pop();
                ans = st.top() + ans;
                st.pop();
            }
            else ans.push_back(s[i]);
        }
        return ans;
    }
};