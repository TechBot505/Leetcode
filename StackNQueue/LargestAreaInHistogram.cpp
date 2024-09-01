class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> left;
        vector<int> right;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) left.push_back(st.top());
            else left.push_back(-1);
            st.push(i);
        }
        while(!st.empty()) st.pop();
        for(int i=n-1; i>=0; i--) {
            while(!st.empty() && heights[st.top()]>=heights[i]) st.pop();
            if(!st.empty()) right.push_back(st.top());
            else right.push_back(n);
            st.push(i);
        }
        reverse(right.begin(), right.end());
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            int area = (heights[i] * (right[i] - left[i] - 1));
            maxArea = max(maxArea, area);
        }
        return maxArea;
    }
};

// Optimized
class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<n; i++) {
            while(!st.empty() && heights[st.top()] > heights[i]) {
                int el = st.top();
                st.pop();
                int nse = i;
                int pse = st.empty() ? -1 : st.top();
                int area = heights[el] * (nse - pse - 1);
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        while(!st.empty()) {
                int el = st.top();
                st.pop();
                int nse = n;
                int pse = st.empty() ? -1 : st.top();
                int area = heights[el] * (nse - pse - 1);
                maxArea = max(area, maxArea);
            }
        return maxArea;
    }
};