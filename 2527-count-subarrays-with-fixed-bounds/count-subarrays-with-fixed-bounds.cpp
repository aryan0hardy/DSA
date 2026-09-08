class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {

        // bruteforce n^2....
        // long count = 0;
        // for (int i = 0; i < nums.size(); i++) {
        //     int mini = INT_MAX, maxi = INT_MIN;
        //     for (int j = i; j < nums.size(); j++) {
        //         mini = min(mini, nums[j]);
        //         maxi = max(maxi, nums[j]);
        //         if (mini == minK && maxi == maxK) ++count;
        //     }
        // }
        // return count;
        int n = nums.size();
        long long ans;
        int lastBad = -1;
        int lastMin = -1;
        int lastMax = -1;
        for (int i = 0; i < n; i++) {
            // no subarray
            if (nums[i] < minK || nums[i] > maxK) {
                lastBad = i;
            }
            if (nums[i] == minK)
                lastMin = i;
            if (nums[i] == maxK)
                lastMax = i;

            int possibleStart = min(lastMin,lastMax);
            if (possibleStart > lastBad) {
                ans += possibleStart - lastBad;
            }
        }
        return ans;
    }
};