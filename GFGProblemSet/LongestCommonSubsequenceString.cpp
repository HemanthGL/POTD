// function to find longest common subsequence

class Solution
{
    // Finding the Longest Common Subsequence of string among two given strings s1 and s2.

    // Problemset Link: https://practice.geeksforgeeks.org/problems/longest-common-subsequence-1587115620/1

    // Approach used DYNAMIC PROGRAMMING by memoizing already computed values called upon in the recursion tree...
    // TOP - DOWN Approach used.
public:
    //Function to find the length of longest common subsequence in two strings.
    int findLCS(string &s1, string &s2, int x, int y, vector<vector<int>> &dp) {

        // base condition
        if (x < 0 || y < 0) {
            // dp[x][y] = 0;
            return 0;
        }

        else if (dp[x][y] != -1)    // if already computed, get val from dp table
            return dp[x][y];

        if (s1[x] == s2[y])        // else if characters match -> 1 + dp[x-1][y-1]
            dp[x][y] = 1 + findLCS(s1, s2, x - 1, y - 1, dp);

        else                        // else if characters don't match -> max(dp[x-1][y], dp[x][y-1])
            dp[x][y] = max(findLCS(s1, s2, x - 1, y, dp), findLCS(s1, s2, x, y - 1, dp));

        return dp[x][y];
    }

    int lcs(int n, int m, string s1, string s2)
    {
        // your code here
        vector<vector<int>> dp(n + 1, vector<int> (m + 1, -1));         // initializing the dp table.

        int ans = findLCS(s1, s2, n - 1, m - 1, dp);
        return ans;
    }
};