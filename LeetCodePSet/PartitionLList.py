# Definition for singly-linked list.
# class ListNode:
#     def __init__(self, val=0, next=None):
#         self.val = val
#         self.next = next
class Solution:
    # Partition List into 2 sections, one which is lesser than target, the other greater.
    # Maintain the insertion order of elements in each section.

    # Problemset Link: https://leetcode.com/problems/partition-list/description/

    # Brute Approach: Replacing nodes in the LL in the required order.
    def partition(self, head: Optional[ListNode], x: int) -> Optional[ListNode]:
        lessarr = []
        morearr = []

        tmp = head
        while tmp != None:
            if tmp.val >= x:
                morearr.append(tmp.val)
            else:
                lessarr.append(tmp.val)
            tmp = tmp.next
        
        n, m = len(lessarr), len(morearr)

        # putting the lesser ones.
        tmp = head
        for i in range(n):
            tmp.val = lessarr[i]
            tmp = tmp.next
        
        # putting the higher ones
        for i in range(m):
            tmp.val = morearr[i]
            tmp = tmp.next
        
        return head
        