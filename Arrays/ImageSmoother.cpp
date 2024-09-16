class Solution {
private:
    int smoother(vector<vector<int>>& img, int row, int col) {
        int n = img.size();
        int m = img[0].size();
        int sum = 0;
        int count = 0;
        for(int i=-1; i<=1; i++) {
            for(int j=-1; j<=1; j++) {
                int nrow = row + i;
                int ncol = col + j;
                if(nrow>=0 && nrow<n && ncol>=0 && ncol<m) {
                    sum += img[nrow][ncol] % 256;
                    count++;
                }
            }
        }
        return sum/count * 256;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int n = img.size();
        int m = img[0].size();
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                img[i][j] += smoother(img, i, j);
            }
        }
        for(int i=0; i<n; i++) {
            for(int j=0; j<m; j++) {
                img[i][j] /= 256;
            }
        }
        return img;
    }
};