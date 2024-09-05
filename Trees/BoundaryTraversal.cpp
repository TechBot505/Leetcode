class Solution {
    bool isLeaf(Node* node) {
        if(!node->left && !node->right) return true;
        return false;
    }
    void addLeftBoundary(Node* root, vector<int> &res) {
        Node* curr = root->left;
        while(curr) {
            if(!isLeaf(curr)) res.push_back(curr->data);
            if(curr->left) curr = curr->left;
            else curr = curr->right;
        }
    }
    void addRightBoundary(Node* root, vector<int> &res) {
        Node* curr = root->right;
        vector<int> temp;
        while(curr) {
            if(!isLeaf(curr)) temp.push_back(curr->data);
            if(curr->right) curr = curr->right;
            else curr = curr->left;
        }
        for(int i=temp.size()-1; i>=0; i--) {
            res.push_back(temp[i]);
        }
    }
    void addLeafNodes(Node* root, vector<int> &res) {
        if(isLeaf(root)) {
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeafNodes(root->left, res);
        if(root->right) addLeafNodes(root->right, res);
    }
public:
    vector <int> boundary(Node *root)
    {
        vector<int> res;
        if(!root) return res;
        if(!isLeaf(root)) res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeafNodes(root, res);
        addRightBoundary(root, res);
        return res;
    }
};