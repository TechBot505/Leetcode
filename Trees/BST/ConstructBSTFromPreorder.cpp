class Solution {
public:
    TreeNode* help(vector<int> &preorder, int &i, int bound) {
        if(i == preorder.size() || preorder[i] > bound) return NULL;
        TreeNode* node = new TreeNode(preorder[i++]);
        node->left = help(preorder, i, node->val);
        node->right = help(preorder, i, bound);
        return node;
    }

    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int i=0;
        return help(preorder, i, INT_MAX);
    }
};