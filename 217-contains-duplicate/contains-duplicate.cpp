class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        int n=nums.size();
        unordered_set<int> st;
        for(int num:nums){
            if(st.find(num)!=st.end())return true; // if duplicate then true
            st.insert(num); // warna new number insert krdo ..
        }
        return false; //  no duplicate then false
    }
};