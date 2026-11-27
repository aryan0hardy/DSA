class Solution {
    public int findCenter(int[][] edges) {
        // return the common value
        // no need to check every edge just compare two 
        if(edges[0][0]==edges[1][0] || edges[0][0]==edges[1][1]){
            return edges[0][0];
        }
        return edges[0][1];
    }
}