class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) {
            return "";
        }
        int max_length = 0;
        string::iterator start = s.begin();
        string::iterator it = s.begin();
        do {
            // use the character as the cord
            int l = 1;
            string::iterator left = it;
            string::iterator right = it;
            while (left-- != s.begin() && ++right != s.end()) {
                if (*left == *right) {
                    l += 2;
                } else {
                    break;
                }
            }
            if (l > max_length) {
                max_length = l;
                start = left + 1;
            }
            // use the character as the last one of the first half
            l = 0;
            left = it + 1;
            right = it;
            while (left-- != s.begin() && ++right != s.end()) {
                if (*left == *right) {
                    l += 2;
                } else {
                    break;
                }
            }
            if (l > max_length) {
                max_length = l;
                start = left + 1;
            }
        } while (++it != s.end());
        string result(start, start + max_length);
        return result;
    }
};
