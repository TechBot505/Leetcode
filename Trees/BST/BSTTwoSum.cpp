class BSTIterator {
    stack<TreeNode*> st;
    bool reverse = true;
    public:
        BSTIterator(TreeNode* root, bool isReverse) {
            reverse = isReverse;
            pushAll(root);
        }
        int next() {
            TreeNode* temp = st.top();
            st.pop();
            if(reverse) pushAll(temp->left);
            else pushAll(temp->right);
            return temp->val;
        }
    private:
        void pushAll(TreeNode* node) {
            while(node) {
                st.push(node);
                if(reverse) {
                    node = node->right;
                }
                else node = node->left;
            }
        }
};
class Solution {
public:
    bool findTarget(TreeNode* root, int k) {
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);
        int i = l.next();
        int j = r.next();
        while(i<j) {
            if(i + j == k) return true;
            else if(i + j < k) i = l.next();
            else j = r.next();
        }
        return false;
    }
};