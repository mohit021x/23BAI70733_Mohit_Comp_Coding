class Solution {
public:
    int minCut(string s) {
        int n = s.size();

        // Step 1: Palindrome DP table
        vector<vector<bool>> pal(n, vector<bool>(n, false));

        for (int i = n - 1; i >= 0; i--) {
            for (int j = i; j < n; j++) {
                if (s[i] == s[j] && (j - i <= 2 || pal[i+1][j-1])) {
                    pal[i][j] = true;
                }
            }
        }

        // Step 2: dp array
        vector<int> dp(n, 0);

        for (int i = 0; i < n; i++) {
            dp[i] = i; // worst case: all cuts

            for (int j = 0; j <= i; j++) {
                if (pal[j][i]) {
                    if (j == 0)
                        dp[i] = 0;
                    else
                        dp[i] = min(dp[i], dp[j-1] + 1);
                }
            }
        }

        return dp[n-1];
    }
};