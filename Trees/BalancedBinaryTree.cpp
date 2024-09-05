class Solution {
public:
    int check(TreeNode* root) {
        if(root == NULL) return 0;
        int lh = check(root->left);
        int rh = check(root->right);
        if(lh == -1 || rh == -1) return -1;
        if(abs(lh-rh) > 1) return -1;
        return 1 + max(lh, rh);
    }
    bool isBalanced(TreeNode* root) {
        if(root == NULL) return 1;
        int temp = check(root);
        if(temp == -1) return 0;
        return 1;
    }
};