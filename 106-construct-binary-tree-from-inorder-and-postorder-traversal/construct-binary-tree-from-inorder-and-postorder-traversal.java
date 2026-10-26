
class Solution {
     private Map<Integer, Integer> inorderMap = new HashMap<>();
    public TreeNode buildTree(int[] inorder, int[] postorder) {
        for (int i = 0; i < inorder.length; i++) {
            inorderMap.put(inorder[i], i);
        }
        return build(postorder,postorder.length -1 , 0, inorder.length - 1);
    }
     private TreeNode build(int[] postorder, int postend, int inStart, int inEnd){
          // no element left in subtree 
        if (inStart > inEnd)
            return null;
        // last element of postorder is the root...
        int rootValue = postorder[postend];
        TreeNode root = new TreeNode(rootValue);
         // find root postn in inorder
        int rootIndex = inorderMap.get(rootValue);
        // no of element in left subtree
        int leftSize = rootIndex - inStart;
        // construct right subtree
        root.right = build(postorder, postend -1, rootIndex + 1, inEnd);
        // construct left subtree
        root.left = build(postorder, postend - 1-(inEnd-rootIndex), inStart, rootIndex - 1);

        return root;
     }
}