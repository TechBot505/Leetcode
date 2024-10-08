class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        map<int, int> mp;
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                int d = i - j - 1 + m;
                if(mp.find(d) != mp.end() && mp[d] != matrix[i][j]) return false;
                mp[d] = matrix[i][j];
            }
        }
        return true;
    }
};

// Brute
class Solution {
public:
    bool isToeplitzMatrix(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        for(int i=0; i<m; i++) {
            int top = matrix[0][i];
            int x = 1;
            int y = i+1;
            while(x<n && y<m) {
                if(matrix[x][y] != top) return false;
                x++;
                y++;
            }
        }
        for(int i=0; i<n; i++) {
            int top = matrix[i][0];
            int x = i+1;
            int y = 1;
            while(x<n && y<m) {
                if(matrix[x][y] != top) return false;
                x++;
                y++;
            }
        }
        return true;
    }
};