class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {
        int n = mat.size();
        int m = mat[0].size();
        if(m*n != r*c) return mat;
        vector<vector<int>> ans(r, vector<int>(c));
        int k = 0;
        int l = 0;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                if(l==ans[0].size()) {
                    l = 0;
                    k++;
                }
                ans[k][l++] = mat[i][j];
            }
        }
        return ans;
    }
};