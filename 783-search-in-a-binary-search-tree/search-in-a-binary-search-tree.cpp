class Solution {
public:
    TreeNode* helper(TreeNode* root, int val) {
        if (root == nullptr)
            return nullptr;

        if (val < root->val)
            return helper(root->left, val);
        else if (val > root->val)
            return helper(root->right, val);
        else
            return root;
    }

    TreeNode* searchBST(TreeNode* root, int val) {
        return helper(root, val);
    }
};