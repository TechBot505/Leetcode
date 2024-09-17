class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {
        int n = letters.size();
        int low = 0, high = n-1;
        if(letters[0] > target || target >= letters[n-1]) return letters[0];
        char ans;
        while(low <= high) {
            int mid = (low + high)/2;
            if(letters[mid] > target) {
                ans = letters[mid];
                high = mid-1;
            } else {
                low = mid+1;
            }
        }
        return ans;
    }
};