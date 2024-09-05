// Recursive
class Solution {
    void traversal(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        traversal(root->left, ans);
        ans.push_back(root->val);
        traversal(root->right, ans);
    }
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        traversal(root, inorder);
        return inorder;
    }
};

// Iterative
class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> inorder;
        if(!root) return inorder;
        stack<TreeNode*> st;
        TreeNode* node = root;
        while(true) {
            if(node) {
                st.push(node);
                node = node->left;
            }
            else {
                if(st.empty()) break;
                node = st.top();
                st.pop();
                inorder.push_back(node->val);
                node = node->right;
            }
        }
        return inorder;
    }
};