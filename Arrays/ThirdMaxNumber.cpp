class Solution {
public:
    int thirdMax(vector<int>& nums) {
        int n = nums.size();
        long long int maxi = LONG_MIN;
        long long int smaxi = LONG_MIN;
        long long int tmaxi = LONG_MIN;
        for(int i=0; i<n; i++) {
            if(nums[i] > maxi) {
                tmaxi = smaxi;
                smaxi = maxi;
                maxi = nums[i];
            }
            else if(nums[i] > smaxi && nums[i] < maxi) {
                tmaxi = smaxi;
                smaxi = nums[i];
            }
            else if(nums[i] > tmaxi && nums[i] < smaxi) {
                tmaxi = nums[i];
            }
        }
        return tmaxi == LONG_MIN ? maxi : tmaxi;
    }
};