class Solution {
public:
    int widthOfBinaryTree(TreeNode* root) {
        queue<pair<TreeNode*, int>> q;
        q.push({root, 0});
        int ans = 0;
        while(!q.empty()) {
            int idx = q.front().second; // To prevent index overflow
            int size = q.size();
            int first = 0;
            int last = 0;
            for(int i=0; i<size; i++) {
                long curr_idx = q.front().second-idx;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first = curr_idx;
                if(i==size-1) last = curr_idx;
                if(node->left) q.push({node->left, curr_idx*2 + 1});
                if(node->right) q.push({node->right, curr_idx*2 + 2});
            }
            ans = max(ans, last-first+1);
        }
        return ans;
    }
};