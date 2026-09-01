class Solution {
public:
    bool solve(int n,long long i){
        if(i==n)return true;
        if(i>n)return false;
        return solve(n,i*3);
    }
    bool isPowerOfThree(int n) {
        if(n<=0)return false;
        if(n==1)return true;
        return solve(n,3);
    }
};