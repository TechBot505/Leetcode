class Solution {
public:
    int countCollisions(string directions) {
        int n = directions.size();
        if(n == 1) return 0;
        stack<char> st;
        st.push(directions[0]);
        int ans = 0;
        for(int i=1; i<n; i++) {
            if(!st.empty() && st.top() == 'R' && directions[i] == 'L') {
                ans += 2;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top() == 'R' && directions[i] == 'S') {
                ans += 1;
                st.pop();
                st.push('S');
            }
            else if(!st.empty() && st.top() == 'S' && directions[i] == 'L') {
                ans += 1;
            }
            else {
                st.push(directions[i]);
            }
        }
        while(!st.empty() && st.top() == 'R') st.pop();
        while(!st.empty()) {
            if(st.top() == 'R') ans++;
            st.pop();
        }
        return ans;
    }
};