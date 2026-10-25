
class Solution {
    private Map<Integer,Integer>inorderMap=new HashMap<>();
    public TreeNode buildTree(int[] preorder, int[] inorder) {
        for(int i=0;i<inorder.length;i++){
            inorderMap.put(inorder[i],i);
        }
      return  build(preorder,0,0,inorder.length-1);

    }
    private TreeNode build(int[] preorder,int preStart,int inStart,int inEnd){
        // no element left in subtree 
        if(inStart > inEnd)return null;
        // first element of preorder is the root...
        int rootValue=preorder[preStart];
        TreeNode root=new TreeNode(rootValue);
        // find root postn in inorder
        int rootIndex=inorderMap.get(rootValue);
        // no of element in left subtree
        int leftSize=rootIndex - inStart;
        // construct left subtree
        root.left=build(preorder,preStart+1,inStart,rootIndex -1);
        // construct right subtree
        root.right=build(preorder,preStart+1+leftSize,rootIndex+1,inEnd);

        return root;

    }
}