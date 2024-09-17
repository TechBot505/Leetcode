class Solution {
public:
    vector<int> shortestToChar(string s, char c) {
        vector<int> v;
        for(int i=0; i<s.size(); i++) {
            if(s[i] == c) v.push_back(i);
        }
        vector<int> ans(s.size(), INT_MAX);
        for(int i=0; i<s.size(); i++) {
            for(int j=0; j<v.size(); j++) {
                ans[i] = min(ans[i], (abs(v[j]-i)));
            }
        }
        return ans;
    }
};