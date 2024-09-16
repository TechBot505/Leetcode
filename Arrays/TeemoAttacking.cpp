class Solution {
public:
    int findPoisonedDuration(vector<int>& timeSeries, int duration) {
        int n = timeSeries.size();
        int count = 0;
        for(int i=0; i<n-1; i++) {
            if(timeSeries[i+1] - timeSeries[i] >=duration) count += duration;
            else {
                count += timeSeries[i+1] - timeSeries[i];
            }
        }
        count += duration;
        return count;
    }
};