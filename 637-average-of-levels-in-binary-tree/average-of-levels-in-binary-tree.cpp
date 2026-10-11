
class Solution {
public:
    void helper(queue<TreeNode*>& q, vector<double>& ans) {
        while (!q.empty()) {
            int size = q.size();  // Number of nodes at this level
            long sum = 0;

            for (int i = 0; i < size; i++) {
                TreeNode* curr = q.front();
                q.pop();  // Remove the current node

                sum += curr->val;

                // Add children for the next level
                if (curr->left != nullptr)
                    q.push(curr->left);

                if (curr->right != nullptr)
                    q.push(curr->right);
            }

            // Calculate and store this level's average
            double avg = (double)sum / size;
            ans.push_back(avg);
        }
    }

    vector<double> averageOfLevels(TreeNode* root) {
        if (root == nullptr)
            return {};

        queue<TreeNode*> q;
        q.push(root);

        vector<double> ans;
        helper(q, ans);

        return ans;
    }
};

