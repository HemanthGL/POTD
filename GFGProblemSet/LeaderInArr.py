class Solution:
    #Back-end complete function Template for Python 3

    # Problemset Link: https://practice.geeksforgeeks.org/problems/leaders-in-an-array-1587115620/1

    # Leaders in an Array: Find all array elements such that each element's all rightside neighbors are smaller than itself in value.

    # APPROACH: iterate from right to left, maintaining max value, if current iterated value is greater than or equal to maintained max, it is a leader in the array.

    # DIFFICULTY: EASY

    # SOLUTION METRICS:
        # TIME COMPLEXITY:  O (N)
        # SPACE COMPLEXITY: O (1) 
    
    # Function to find the leaders in the array.
    def leaders(self, A, n):
        #Code here
        ans = [A[n-1]]
        mx = ans[0]
        for i in range(n-2, -1, -1):
            if A[i] >= mx:
                mx = A[i]
                ans.append(A[i])
        
        # returning the REVERSED List (Since construction order from right to left)
        return ans[::-1]
