class Solution {
public:
    int minval = INT_MAX;
    int prev = -1;

    void helper(TreeNode* root) {
        if (root == nullptr)
            return;

        helper(root->left);

        if (prev != -1) {
            minval = min(minval, root->val - prev);
        }

        prev = root->val;

        helper(root->right);
    }

    int getMinimumDifference(TreeNode* root) {
        helper(root);
        return minval;
    }
};