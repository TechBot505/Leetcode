class Solution {
public:
    TreeNode* inorderSuccessor(TreeNode* root, TreeNode* p) {
        TreeNode* successor = NULL;
        while(root) {
            if(p->val >= root->val) {
                root = root->right;
            } else {
                successor = root->val;
                root = root->left;
            }
        }
        return successor;
    }
}