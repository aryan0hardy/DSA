
class Solution {
    int ans=0;
    void helper(TreeNode root,int curr){
        if(root==null)return ;
        curr=curr*2+root.val;
        if(root.left==null && root.right==null){
            ans+=curr;
            return;
        }
        helper(root.left,curr);
        helper(root.right,curr);
    }
    public int sumRootToLeaf(TreeNode root) {
        helper(root,0);
        return ans;
    }
}