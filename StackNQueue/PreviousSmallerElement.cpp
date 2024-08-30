class Solution{
public:
    vector<int> leftSmaller(int n, int a[]){
        // code here
        stack<int> st;
        vector<int> ans;
        for(int i=0; i<n; i++) {
            while(!st.empty() && st.top()>=a[i]) st.pop();
            if(!st.empty()) ans.push_back(st.top());
            else ans.push_back(-1);
            st.push(a[i]);
        }
        return ans;
    }
};