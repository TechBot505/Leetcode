class Solution {
    int findLeft(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->left;
        }
        return height;
    }
    int findRight(TreeNode* node) {
        int height = 0;
        while(node) {
            height++;
            node = node->right;
        }
        return height;
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        int lh = findLeft(root);
        int rh = findRight(root);
        if(lh == rh) return (1<<lh) - 1;
        return 1 + countNodes(root->left) + countNodes(root->right);
    }
};

class Solution {
    void preorderTraversal(TreeNode* node, vector<int> &preorder) {
        if(!node) return;
        preorder.push_back(node->val);
        preorderTraversal(node->left, preorder);
        preorderTraversal(node->right, preorder);
    }
public:
    int countNodes(TreeNode* root) {
        if(!root) return 0;
        vector<int> preorder;
        preorderTraversal(root, preorder);
        return preorder.size();
    }
};