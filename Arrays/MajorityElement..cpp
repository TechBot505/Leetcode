class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size();
        int count = 0;
        int el;
        for(int i=0; i<n; i++) {
            if(count == 0) {
                el = nums[i];
                count++;
            }
            else if(nums[i] == el) {
                count++;
            }
            else count--;
        }
        int cnt = 0;
        for(int i=0; i<n; i++) {
            if(nums[i] == el) {
                cnt++;
            }
        }
        if(cnt > n/2) return el;
        return 0;
    }
};