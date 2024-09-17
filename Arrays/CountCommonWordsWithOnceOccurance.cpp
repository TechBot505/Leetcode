class Solution {
public:
    int countWords(vector<string>& words1, vector<string>& words2) {
        unordered_map<string, int> mp;
        for(auto it : words1) {
            if(mp[it] == 0) mp[it] = 1;
            else if(mp[it] == 1) mp[it] = -1;
        }
        for(auto it : words2) {
            if(mp[it] == 1) mp[it] = 2;
            else if(mp[it] == 2) mp[it] = -1;
        }
        int count = 0;
        for(auto it : mp) {
            if(it.second == 2) count++;
        }
        return count;
    }
};