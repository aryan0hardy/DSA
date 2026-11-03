public class Solution {
    public String longestPalindrome(String s) {
        int start = 0;
        int maxlen = 0;

        // i is the centre index jiske along expand krege
        for (int i = 0; i < s.length(); i++) {
            // odd length k liye 
            int len1 = expand(s, i, i);
            // even length k liye 2 centre idx common hoge
            int len2 = expand(s, i, i + 1);
            // final len
            int len = Math.max(len1, len2);

            if (len > maxlen) {
                maxlen = len;
                start = i - (len - 1) / 2;
            }
        }
        return s.substring(start, maxlen + start);
    }

    public int expand(String s, int left, int right) {
        while (left >= 0 && right < s.length() && s.charAt(left) == s.charAt(right)) {
            left--;
            right++;
        }
        return right - left - 1;
    }
}
