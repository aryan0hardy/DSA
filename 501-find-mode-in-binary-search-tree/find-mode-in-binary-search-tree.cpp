class Solution {
public:
    void helper(TreeNode* root, unordered_map<int, int>& mp) {
        if (root == nullptr)
            return;

        mp[root->val]++;

        helper(root->left, mp);
        helper(root->right, mp);
    }

    vector<int> findMode(TreeNode* root) {
        unordered_map<int, int> mp; 
        vector<int> ans;

        helper(root, mp);

        int maxfreq = 0;
        // find max freq
        for (auto i : mp) {
            maxfreq = max(maxfreq, i.second);
        }
// store val with max freq
        for (auto i : mp) {
            if (i.second == maxfreq) {
                ans.push_back(i.first);
            }
        }

        return ans;
    }
};