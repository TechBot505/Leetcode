class Solution {
private:
    void create(vector<int> &nums, vector<int> &p, int freq[], vector<vector<int>> &ans) {
        if(p.size() == nums.size()) {
            ans.push_back(p);
            return;
        }
        for(int i=0; i<nums.size(); i++) {
            if(!freq[i]) {
                p.push_back(nums[i]);
                freq[i] = 1;
                create(nums, p, freq, ans);
                freq[i] = 0;
                p.pop_back();
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> p;
        int freq[nums.size()];
        for(int i=0; i<nums.size(); i++) freq[i] = 0;
        create(nums, p, freq, ans);
        return ans;
    }
};