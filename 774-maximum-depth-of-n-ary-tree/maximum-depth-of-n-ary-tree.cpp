/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    int ans;
    void helper(Node* root, queue<Node*>& q) {
        if (root == nullptr)
            return;
        while (!q.empty()) {
            int n = q.size();
            for (int i = 0; i < n; i++) {
                Node* curr = q.front();
                q.pop();
                for (auto child : curr->children) {
                    q.push(child);
                }
            }
            ans++;
        }
    }
    int maxDepth(Node* root) {
        queue<Node*> q;
        q.push(root);
        ans = 0;
        helper(root, q);
        return ans;
    }
};