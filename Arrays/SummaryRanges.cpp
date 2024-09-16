class Solution {
public:
    vector<string> summaryRanges(vector<int>& nums) {
        int n = nums.size();
        vector<string> ans;
        if(n==0) return ans;
        int start = nums[0];
        int end = nums[0];
        int cnt = nums[0];
        for(int i=1; i<n; i++) {
            if(cnt+1 == nums[i]) {
                end++;
                cnt++;
            } else {
                string temp = "";
                if(start != end) {
                    temp += to_string(start) + "->" + to_string(end);
                } else {
                    temp += to_string(start);
                }
                ans.push_back(temp);
                start = nums[i];
                end = nums[i];
                cnt = nums[i];
            }
        }
        string temp = "";
        if(start != end) {
            temp += to_string(start) + "->" + to_string(end);
        } else {
            temp += to_string(start);
        }
        ans.push_back(temp);
        return ans;
    }
};