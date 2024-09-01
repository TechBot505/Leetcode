class Solution {
public:
    int solve(vector<int> &heights, int m) {
        stack<int> st;
        int maxArea = 0;
        for(int i=0; i<=m; i++) {
            while(!st.empty() && (i==m || heights[st.top()] >= heights[i])) {
                int height = heights[st.top()];
                st.pop();
                int width = 0;
                if(st.empty()) width = i;
                else width = i - st.top() -1;
                int area = height*width;
                maxArea = max(area, maxArea);
            }
            st.push(i);
        }
        return maxArea;
    }

    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        int ans = 0;
        vector<int> heights(m, 0);
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(matrix[i][j] == '1') heights[j]++;
                else heights[j] = 0;
            }
            int area = solve(heights, m);
            ans = max(area, ans);
        }
        return ans;
    }
};