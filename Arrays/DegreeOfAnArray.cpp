class Solution {
public:
    int findShortestSubArray(vector<int>& nums) {
        int n = nums.size();
        if(n==1) return 1;
        unordered_map<int, vector<int>> mp;
        for(int i=0; i<n; i++) {
            mp[nums[i]].push_back(i);
        }
        int degree = 0;
        int ans = INT_MAX;
        for(auto it : mp) {
            if(it.second.size() == degree) {
                ans = min(ans, it.second[it.second.size() - 1] - it.second[0]);
            }
            else if(it.second.size() > degree) {
                ans = it.second[it.second.size() - 1] - it.second[0];
                degree = it.second.size();
            }
        }
        return ans + 1;
    }
};