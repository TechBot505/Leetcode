class Solution {
private:
    void createSubset(int ind, vector<int> &nums, vector<int> &subset, vector<vector<int>> &ans) {
        ans.push_back(subset);
        for(int i=ind; i<nums.size(); i++) {
            if(i>0 && i!=ind && nums[i] == nums[i-1]) continue;
            subset.push_back(nums[i]);
            createSubset(i+1, nums, subset, ans);
            subset.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        vector<int> subset;
        createSubset(0, nums, subset, ans);
        return ans;
    }
};