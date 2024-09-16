class Solution {
public:
    vector<string> findWords(vector<string>& words) {
        string s1="qwertyuiop";
        string s2="asdfghjkl";
        string s3="zxcvbnm";
        map<char,int> mp;
        for(auto c : s1) {
            mp[c] = 1;
        }
        for(auto c : s2) {
            mp[c] = 2;
        }
        for(auto c : s3) {
            mp[c] = 3;
        }
        vector<string> ans;
        for(auto r : words) {
            bool flag = true;
            int row = mp[tolower(r[0])]; 
            for(auto c : r) {
                if(mp[tolower(c)] != row) { 
                    flag = false;
                    break;
                }
            }
            if(flag) {
                ans.push_back(r);
            }
        }
        return ans;
    }
};