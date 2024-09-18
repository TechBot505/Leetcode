class Solution {
private:
    void createSubset(int ind, vector<int> &nums, vector<int>&subset, vector<vector<int>> &ans) {
        if(ind == nums.size()) {
            ans.push_back(subset);
            return;
        }
        subset.push_back(nums[ind]);
        createSubset(ind+1, nums, subset, ans);
        subset.pop_back();
        createSubset(ind+1, nums, subset, ans);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> subset;
        createSubset(0, nums, subset, ans);
        return ans;
    }
};