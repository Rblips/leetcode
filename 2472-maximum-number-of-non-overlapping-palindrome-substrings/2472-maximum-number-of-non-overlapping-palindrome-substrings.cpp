class Solution {
public:
    int maxPalindromes(string s, int k) {
        int n = s.size();
        vector<int> dp(n + 1, 0);

        // dp[i] = maximum number of valid palindromes
        // using the first i characters

        for (int i = 0; i < n; i++) {

            // Don't end a palindrome at i
            dp[i + 1] = max(dp[i + 1], dp[i]);

            // Odd length palindrome
            int l = i, r = i;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break; // shortest valid palindrome is enough
                }
                l--;
                r++;
            }

            // Even length palindrome
            l = i;
            r = i + 1;
            while (l >= 0 && r < n && s[l] == s[r]) {
                if (r - l + 1 >= k) {
                    dp[r + 1] = max(dp[r + 1], dp[l] + 1);
                    break;
                }
                l--;
                r++;
            }
        }

        return dp[n];
    }
};