class Solution {
public:
    vector<int> getRow(int rowIndex) {
        long long ans = 1;
        rowIndex++;
        vector<int> row;
        row.push_back(ans);
        for(int i=1; i<rowIndex; i++) {
            ans = ans * (rowIndex-i);
            ans = ans / i;
            row.push_back(ans);
        }
        return row;
    }
};