class Solution {
    public:
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> result;
        vector<int> path;
        dfs(root, path, result);
        return result;
    }
    void dfs(TreeNode* node, vector<int>& path, vector<string>& result) {
        if (!node) return;
        path.push_back(node->val);
        if (!node->left && !node->right) {
            string pathStr;
            for (int i = 0; i < path.size(); ++i) {
                pathStr += to_string(path[i]);
                if (i < path.size() - 1) {
                    pathStr += "->";
                }
            }
            result.push_back(pathStr);
        } else {
            dfs(node->left, path, result);
            dfs(node->right, path, result);
        }
        path.pop_back();
    }

};