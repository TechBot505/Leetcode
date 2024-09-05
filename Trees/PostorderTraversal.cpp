// Recursive
class Solution {
    void traversal(TreeNode* root, vector<int> &ans) {
        if(!root) return;
        traversal(root->left, ans);
        traversal(root->right, ans);
        ans.push_back(root->val);
    }
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        traversal(root, postorder);
        return postorder;
    }
};

// Iterative using 2 stacks
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> st1;
        stack<TreeNode*> st2;
        st1.push(root);
        while(!st1.empty()) {
            TreeNode* node = st1.top();
            st1.pop();
            st2.push(node);
            if(node->left) st1.push(node->left);
            if(node->right) st1.push(node->right);
        }
        while(!st2.empty()) {
            postorder.push_back(st2.top()->val);
            st2.pop();
        }
        return postorder;
    }
};

// Iterative using 1 stack
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector<int> postorder;
        if(!root) return postorder;
        stack<TreeNode*> st;
        TreeNode* curr = root;
        while(curr || !st.empty()) {
            if(curr) {
                st.push(curr);
                curr = curr->left;
            }
            else {
                TreeNode* temp = st.top()->right;
                if(!temp) {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->val);
                    while(!st.empty() && temp == st.top()->right) {
                        temp = st.top();
                        st.pop();
                        postorder.push_back(temp->val);
                    }
                }
                else {
                    curr = temp;
                }
            }
        }
        return postorder;
    }
};
