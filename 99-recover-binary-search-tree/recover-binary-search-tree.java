
class Solution {
    TreeNode prev=null; // to store prev node
    TreeNode first=null; // first misplaced
    TreeNode second=null; // second misplaced
    void inorder(TreeNode root){
        if(root==null)return;
        inorder(root.left);
        // if prev has something and its val is greater than root .. means violation . inorder stores increasing order so update first and second
        if(prev!=null && prev.val>root.val){
            if(first==null){ // update first only one time 
                first=prev;
            }
            second=root; // update second only after first 
        }
        prev=root; // update prev for each iteration
        inorder(root.right);

    }
    public void recoverTree(TreeNode root) {
        inorder(root);

        // swap first and second misplaced value
        int temp=first.val;
        first.val=second.val;
        second.val=temp;

    }
}