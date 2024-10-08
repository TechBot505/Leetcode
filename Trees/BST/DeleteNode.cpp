class Solution {
public:
    TreeNode* findLastLeft(TreeNode* root) {
        if(!root->left) return root;
        return findLastLeft(root->left);
    }

    TreeNode* helper(TreeNode* root) {
        if(!root->left) return root->right;
        else if(!root->right) return root->left;
        TreeNode* leftChild = root->left;
        TreeNode* lastLeft = findLastLeft(root->right);
        lastLeft->left = leftChild;
        return root->right;
    }

    TreeNode* deleteNode(TreeNode* root, int key) {
        if(!root) return NULL;
        if(root->val == key) return helper(root);
        TreeNode* dummy = root;
        while(root) {
            if(root->val > key) {
                if(root->left && root->left->val == key) {
                    root->left = helper(root->left);
                    break;
                }
                else {
                    root = root->left;
                }
            }
            else {
                if(root->right && root->right->val == key) {
                    root->right = helper(root->right);
                    break;
                }
                else {
                    root = root->right;
                }
            }
        }
        return dummy;
    }
};