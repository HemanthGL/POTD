#User function Template for python3

class Solution:
    # Problem Link: https://practice.geeksforgeeks.org/problems/coin-change2448/1

    # DP approach utilized to pick from already computed values through memoization to optimize the recursion tree...
    # Print the total number of ways to get sum from given option of coins
        # we assume we have an infinite supply of coins of each type...
    def count(self, coins, N, sum):
        # code here 
        dp = [0] * (sum + 1)
        dp[0] = 1
        for j in coins:
            # print(j)
            if j < sum + 1:
                dp[j] += 1
            
            for k in range(j + 1, sum + 1):
                dp[k] += dp[k-j]
        
        return dp[sum]