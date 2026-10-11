
class Solution {
public:
int ans=0;
    void helper(TreeNode* root,int curr){
        if(root==nullptr)return;
        curr=curr*2+root->val;  // binary to decimal conversion
        if(!root->left && !root->right){ // leaf node h to ans m us binary k add krdege
            ans+=curr;
            return;
        }
        helper(root->left,curr);// curr ki value upr wali pass hogi same dono k liye us root node tk
        helper(root->right,curr);
    }
    int sumRootToLeaf(TreeNode* root) {
        helper(root,0); // initially curr ko 0 se initialize krke pass krege
        return ans;
    }
};