class Solution {
public:
    int maximumLengthSubstring(string s) {
        int freq[26] = {};

        int left = 0;

        int ans = 0;

        for (int right = 0; right < s.size(); right++) {
            freq[s[right] - 'a']++;  // freq ko bdate jao

            while (freq[s[right] - 'a'] > 2) { // left ko bdao jb tk freq 2  se jyada h aur window chhota kro

                freq[s[left] - 'a']--;

                left++;
            }

            ans = max(ans, right - left + 1); // max no. jo bhi aaye use store kro
        }

        return ans;
    }
};