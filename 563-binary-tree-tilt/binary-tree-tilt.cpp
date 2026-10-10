class Solution {
public:
    int ans = 0;  // Stores the total tilt of the entire tree

    // Returns the sum of all nodes in the subtree
    int sum(TreeNode* root) {
        // Base case: an empty subtree has sum 0
        if (root == nullptr) {
            return 0;
        }

        // Calculate the sum of the left subtree
        int left = sum(root->left);

        // Calculate the sum of the right subtree
        int right = sum(root->right);

       // store the sum of abs diff btw left & right subtree
        ans += abs(left - right);

        // Return the total sum of this subtree to its parent
        return root->val + left + right;
    }

    int findTilt(TreeNode* root) {
        

        sum(root);  // Calculate subtree sums and accumulate tilts

        return ans;  // Return the total tilt of the tree
    }
};