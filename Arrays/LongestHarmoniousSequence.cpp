class Solution {
public:
    int findLHS(vector<int>& nums) {
        int n = nums.size();
        map<int, int> mp;
        int maxCount = 0;
        for(int i=0; i<n; i++) {
            int x = nums[i];
            mp[x]++;
            if(mp.find(x+1) != mp.end()) {
                maxCount = max(maxCount, mp[x+1]+mp[x]);
            }
            if(mp.find(x-1) != mp.end()) {
                maxCount = max(maxCount, mp[x-1]+mp[x]);
            }
        }
        return maxCount;
    }
};