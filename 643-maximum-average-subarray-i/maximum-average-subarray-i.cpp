class Solution {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        int left =0;
        int sum=0;
        for (int i=0;i<k;i++){
            sum+=nums[i];
        }
        int maxSum=sum;
        for(int right=k;right<nums.size();right++){
            sum+=nums[right];
            sum-=nums[left];
            left++;
            maxSum=max(maxSum,sum);

        }
        return double(maxSum)/k;
    }
};