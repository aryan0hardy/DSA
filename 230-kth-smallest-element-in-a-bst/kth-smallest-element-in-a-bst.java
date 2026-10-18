
class Solution {
    int count = 0;

    int helper(TreeNode root, int k) {
        if (root == null) {
            return -1;
        }

        // 1. Traverse left subtree
        int left = helper(root.left, k);
        if (left != -1) {
            return left;
        }

        // 2. Visit root
        count++;

        if (count == k) {
            return root.val;
        }

        // 3. Traverse right subtree
        int right = helper(root.right, k);
        if (right != -1) {
            return right;
        }

        return -1;
    }

    public int kthSmallest(TreeNode root, int k) {
        count = 0;
        return helper(root, k);
    }
}
