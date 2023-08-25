#User function Template for python3
class Solution:

	# Problemset: To check if given string is a Palindrome.
	# Link: https://practice.geeksforgeeks.org/problems/palindrome-string0817/1

	# Approach: Create a deep copy and reverse it, finally compare both strings to estimate whether a Palindrome or not

	# Metrics:
		# TC: O(N), to reverse the string of the deep copy
		# SC: O(len(S)), to create the deep copy

	# Alternate Approach: Maintain two pointers at each end of string, one by one compare each character moving in opposing directions.

	def isPalindrome(self, S):
		# code here
		cp = str(S)
		cp = cp[::-1]
		
		if cp == S:
		    return 1
	    else:
	        return 0

