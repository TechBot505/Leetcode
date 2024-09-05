class Solution {
public:
    int sum(TreeNode* root, int &maxi) {
        if(!root) return 0;
        int leftSum = max(0, sum(root->left, maxi));
        int rightSum = max(0, sum(root->right, maxi));
        maxi = max(maxi, root->val + leftSum + rightSum);
        return root->val + max(leftSum, rightSum);
    }

    int maxPathSum(TreeNode* root) {
        int maxi = INT_MIN;
        int temp = sum(root, maxi);
        return maxi;
    }
};