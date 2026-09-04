class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
        int n=nums.size();
        vector<int>prefix(n,0);
        vector<int>suffix(n,0);
        int mn=INT_MAX;
        int mx=INT_MIN;
        for(int i=n-1 ;i>=0;i--){
            mn=min(mn,nums[i]);
            suffix[i]=mn;
        }
        for(int i=0 ;i<n;i++){
            mx=max(mx,nums[i]);
            prefix[i]=mx;
        }
        for(int i=0;i<n;i++){
            if(prefix[i]-suffix[i]<=k)return i;
        }
        return -1;
    }
};