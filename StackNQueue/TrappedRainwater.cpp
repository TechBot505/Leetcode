class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total = 0, leftMax = 0, rightMax = 0;
        int left = 0;
        int right = n-1;
        while(left<=right) {
            if(height[left] <= height[right]) {
                if(leftMax > height[left]) {
                    total += leftMax - height[left];
                } else {
                    leftMax = height[left];
                }
                left++;
            }
            else {
                if(rightMax > height[right]) {
                    total += rightMax - height[right];
                } else {
                    rightMax = height[right];
                }
                right--;
            }
        }
        return total;
    }
};


class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int prefix[n], suffix[n];
        for(int i=0; i<n; i++) {
            if(i==0) prefix[i] = height[i];
            else prefix[i] = max(prefix[i-1], height[i]);
        }
        for(int i=n-1; i>=0; i--) {
            if(i==n-1) suffix[i] = height[i];
            else suffix[i] = max(suffix[i+1], height[i]);
        }
        int total = 0;
        for(int i=0; i<n; i++) {
            int prefixMax = prefix[i];
            int suffixMax = suffix[i];
            if(height[i] < prefixMax && height[i] < suffixMax) {
                total += min(prefixMax, suffixMax) - height[i];
            }
        }
        return total;
    }
};