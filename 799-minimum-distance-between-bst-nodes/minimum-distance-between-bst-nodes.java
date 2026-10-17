
class Solution {
    int mindiff = Integer.MAX_VALUE;
int prev=-1;
    void helper(TreeNode root) {
        if (root == null)
            return ;
        helper(root.left);
        if(prev!=-1){
            mindiff=Math.min(mindiff,root.val-prev);
        }
        prev=root.val;
        helper(root.right);
        
        
    }

    public int minDiffInBST(TreeNode root) {
        mindiff = Integer.MAX_VALUE;
        prev=-1;
         helper(root);
return mindiff;
    }
}