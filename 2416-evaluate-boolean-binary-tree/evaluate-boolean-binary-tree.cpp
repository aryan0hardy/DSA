
class Solution {
public:
    bool evaluateTree(TreeNode* root) {
        if (root->left == nullptr || root->right == nullptr) {
            return root->val == 1;
        }
        bool left = evaluateTree(root->left);
        bool right = evaluateTree(root->right);
        if (root->val == 2) {
            return left || right;
        }
        return left && right;
    }
};