class Solution {
public:
// aadha krte jao jb tk sqrt mil ni jata wrna st and end ki value upadte kro..
    int mySqrt(int x) {
        if(x<2)return x;
        int mid,st=0,end=x,ans;
        while(st<=end){
            mid=(st+end)/2;
            if(mid==x/mid)return mid;
            else if(mid<x/mid){
                ans=mid;
                st=mid+1;
            }
            else {
                
                end=mid-1;
            }
        }
        return ans;
    }
};