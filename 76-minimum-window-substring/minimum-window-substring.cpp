class Solution {
public:
    string minWindow(string s, string t) {

        int n = s.length();

        if(t.length() > n)
            return "";

        unordered_map<char, int> mp;

        // Store frequency of every character required from t
        for(char &ch : t) {
            mp[ch]++;
        }

        int i = 0;                  // left pointer
        int j = 0;                  // right pointer

        int start_i = 0;            // starting index of best window
        int minWindowSize = INT_MAX;

        int reqCount = t.length();  // characters still required

        // Sliding window
        while(j < n) {

            char ch = s[j];

            // If this character is still required
            if(mp[ch] > 0) {
                reqCount--;
            }

            // Decrease frequency
            mp[ch]--;

            // We have all required characters
            while(reqCount == 0) {

                // Current window size
                int currWindowSize = j - i + 1;

                // Update minimum window
                if(minWindowSize > currWindowSize) {
                    minWindowSize = currWindowSize;
                    start_i = i;
                }

                // Remove s[i] from window
                mp[s[i]]++;

                // If frequency becomes positive,
                // this character is now missing
                if(mp[s[i]] > 0) {
                    reqCount++;
                }

                // ALWAYS move left pointer
                i++;
            }

            // Move right pointer
            j++;
        }

        // No valid window found
        if(minWindowSize == INT_MAX)
            return "";

        return s.substr(start_i, minWindowSize);
    }
};