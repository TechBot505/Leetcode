class Solution {
public:
    int diameter(TreeNode* root, int &maxi) {
        if(!root) return 0;
        int lh = diameter(root->left, maxi);
        int rh = diameter(root->right, maxi);
        maxi = max(maxi, lh+rh);
        return 1 + max(lh, rh);
    }
    int diameterOfBinaryTree(TreeNode* root) {
        int maxi = 0;
        int temp = diameter(root, maxi);
        return maxi;
    }
};