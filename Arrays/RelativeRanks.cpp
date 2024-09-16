class Solution {
private:
    static bool comp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first >= b.first) return true;
        else return false;
    }
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        vector<pair<int, int>> arr;
        int n = score.size();
        for(int i=0; i<n; i++) {
            arr.push_back({score[i], i});
        }
        sort(arr.begin(), arr.end(), comp);
        vector<string> ans(n);
        for(int i=0; i<n; i++) {
            int num = arr[i].first;
            int index = arr[i].second;
            if(i==0) ans[index] = "Gold Medal";
            else if(i==1) ans[index] = "Silver Medal";
            else if(i==2) ans[index] = "Bronze Medal";
            else ans[index] = to_string(i+1);
        }
        return ans;
    }
};