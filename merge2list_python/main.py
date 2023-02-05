# Definition for singly-linked list.
from typing import Optional


class ListNode:
    def __init__(self, val=0, next=None):
        self.val = val
        self.next = next

class Solution:
    def mergeTwoLists(self, list1: Optional[ListNode], list2: Optional[ListNode]) -> Optional[ListNode]:
        Head = ListNode()
        temp = Head
        while list1 is not None and list2 is not None:
            if list1.val < list2.val:
                temp.val = list1.val
                list1 = list1.next
            else:
                temp.val = list2.val
                list2 = list2.next
            temp.next = ListNode()
            temp = temp.next

        if list1:
            temp.val = list1.val
            temp.next =list1.next
        elif list2:
            temp.val = list2.val
            temp.next = list2.next
        else:
            Head = None

        return Head;


sol = Solution()

list_head = ListNode(0)
list2_head = ListNode(0)
temp = ListNode(1)
temp2 = ListNode(1)

list_head.next = temp
list2_head.next = temp2

for i in range(1, 3):
    temp.next = ListNode(i + 1)
    temp2.next = ListNode(i + 1)
    temp = temp.next
    temp2 = temp2.next



test = sol.mergeTwoLists(list_head, list2_head)
test = sol.mergeTwoLists(list_head, list2_head)