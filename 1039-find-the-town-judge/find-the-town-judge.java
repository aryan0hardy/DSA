
class Solution {
    public int findJudge(int n, int[][] trust) {

        int[] in = new int[n + 1];
        int[] out = new int[n + 1];

        // Count indegree and outdegree
        for (int i = 0; i < trust.length; i++) {
            // person  a trusting person b
            int a = trust[i][0];
            int b = trust[i][1];

            out[a]++;
            in[b]++;
        }

        // Find the judge
        for (int i = 1; i <= n; i++) {
            // everyone trust him but he dont 
            if (in[i] == n - 1 && out[i] == 0) {
                return i;
            }
        }

        return -1;
    }
}
