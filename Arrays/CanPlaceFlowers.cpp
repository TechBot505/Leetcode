class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int m = flowerbed.size();
        if(n==0) return true;
        int p = 1;
        for(int i=0; i<m; i++) {
            if(flowerbed[i] == 0) p++;
            else p=0;
            if(p==3) {
                n--;
                p=1;
            }
            else if(p==2 && i==m-1) n--;
            if(n==0) return true;
        }
        return n==0;
    }
};