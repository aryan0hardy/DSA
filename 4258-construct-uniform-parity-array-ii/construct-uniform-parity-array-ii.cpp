class Solution {
public:
    bool uniformArray(vector<int>& nums1) {
        int minOdd = INT_MAX;
        int minEven = INT_MAX;
        for (int i : nums1) {
            if (i % 2 != 0)
                minOdd = min(minOdd, i);
            else {
                minEven = min(minEven, i);
            }
        }
        if (minOdd == INT_MAX)
            return true;
        return minOdd < minEven;
    }
};