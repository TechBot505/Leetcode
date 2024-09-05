class Solution {
public:
    bool preorder(TreeNode* p, TreeNode* q) {
        if(!p || !q) return p==q;
        return (p->val==q->val) && preorder(p->left, q->left) && preorder(p->right, q->right);
    }
    bool isSameTree(TreeNode* p, TreeNode* q) {
        return preorder(p, q);
    }
};