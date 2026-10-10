/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    bool isSame(TreeNode* root, TreeNode* subRoot){
        if(!root && !subRoot)return true;
        if(!root || !subRoot)return false;
        if(root->val != subRoot->val)return false;

        
        
        return isSame(root->left,subRoot->left)&&
         isSame(root->right,subRoot->right);
    }
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==nullptr)return true; // agr subroot hi null h to true return ...
        if(root==nullptr)return false; // subroot null ni h and root null h to false...
        if(isSame(root,subRoot))return true; 
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot) ;  // root k left aur right part m check krege.. eak m bhi mil gya to true return krdo...
    }
};