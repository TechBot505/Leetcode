class Solution {
private:
    void sumIt(int i, int target, vector<int>& candidates, vector<int> &temp, vector<vector<int>> &ans) {
        if(i==candidates.size()) {
            if(target == 0) {
                ans.push_back(temp);
            }
            return;
        }
        if(candidates[i] <= target) {
            temp.push_back(candidates[i]);
            sumIt(i, target-candidates[i], candidates, temp, ans);
            temp.pop_back();
        }
        sumIt(i+1, target, candidates, temp, ans);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> temp;
        sumIt(0, target, candidates, temp, ans);
        return ans;
    }
};