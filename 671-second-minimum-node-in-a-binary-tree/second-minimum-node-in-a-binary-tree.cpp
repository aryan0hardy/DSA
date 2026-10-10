class Solution {
public:
    void helper(TreeNode* root, int& min1, int& min2, bool& found) {
        if (root == nullptr)
            return;

        if (root->val < min1) {
            if (min1 != INT_MAX || found) {
                min2 = min1;
                found = true;
            }
            min1 = root->val;
        }
        else if (root->val > min1 && (!found || root->val < min2)) {
            min2 = root->val;
            found = true;
        }

        helper(root->left, min1, min2, found);
        helper(root->right, min1, min2, found);
    }

    int findSecondMinimumValue(TreeNode* root) {
        int min1 = INT_MAX;
        int min2 = INT_MAX;
        bool found = false;

        helper(root, min1, min2, found);

        return found ? min2 : -1;
    }
};