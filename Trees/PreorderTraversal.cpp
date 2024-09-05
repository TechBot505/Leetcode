// Recursive
class Solution {
    void traversal(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        ans.push_back(root->val);
        traversal(root->left, ans);
        traversal(root->right, ans);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        traversal(root, preorder);
        return preorder;
    }
};

// Iterative
class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector<int> preorder;
        if(!root) return preorder;
        stack<TreeNode*> st;
        st.push(root);
        while(!st.empty()) {
            TreeNode* node = st.top();
            st.pop();
            preorder.push_back(node->val);
            if(node->right) st.push(node->right);
            if(node->left) st.push(node->left);
        }
        return preorder;
    }
};