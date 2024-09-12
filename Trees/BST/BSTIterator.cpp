class BSTIterator {
    stack<TreeNode*> st;
public:
    BSTIterator(TreeNode* root) {
        pushAll(root);
    }
    int next() {
        TreeNode* temp = st.top();
        st.pop();
        pushAll(temp->right);
        return temp->val;
    }
    bool hasNext() {
        return !st.empty();
    }
    void pushAll(TreeNode* node) {
        while(node) {
            st.push(node);
            node = node->left;
        }
    }
};