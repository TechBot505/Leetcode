class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        if(n<3) return false;
        stack<int> st;
        int maxThirdEle = INT_MIN;
        for(int i=n-1; i>=0; i--) {
            int curr = nums[i];
            if(curr < maxThirdEle) {
                return true;
            }
            while(!st.empty() && st.top() < curr) {
                maxThirdEle = st.top();
                st.pop();
            }
            st.push(curr);
        }
        return false;
    }
};