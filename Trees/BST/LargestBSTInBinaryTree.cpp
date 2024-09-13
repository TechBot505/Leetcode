class NodeValue {
private:
    int minNode, maxNode, maxSize;
public:
    NodeValue(int minNode, int maxNode, int maxSize) {
        this->minNode = minNode;
        this->maxNode = maxNode;
        this->maxSize = maxSize;
    }
};

class Solution {
private:
    NodeValue largestBSTSubtreeHelper(TreeNode* node) {
        if(node == NULL) {
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        NodeValue left = largestBSTSubtreeHelper(node->left);
        NodeValue right = largestBSTSubtreeHelper(node->right);
        if(left.maxNode < node->val && right.minNode > node->val) {
            return NodeValue(min(left.minNode, node->val), max(right.maxNode, node->val), left.maxSize + right.maxSize + 1);
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
public:
    int largestBSTSubstree(TreeNode* root) {
        return largestBSTSubtreeHelper(root).maxSize;
    }
};