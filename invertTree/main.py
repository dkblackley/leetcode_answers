# Definition for a binary tree node.
from typing import Optional


class TreeNode:
    def __init__(self, val=0, left=None, right=None):
        self.val = val
        self.left = left
        self.right = right

class Solution:
    def invertTree(self, root: Optional[TreeNode]) -> Optional[TreeNode]:

        if not root:
            return root

        temp = root.left
        root.left = root.right
        root.right = temp

        if root.left:
            self.invertTree(root.left)
        if root.right:
            self.invertTree(root.right)

        return root



right = TreeNode(val=None)
left = TreeNode(val=2)
root = TreeNode(val=1, left=left, right=right)

sol = Solution()
temp = sol.invertTree(root)
temp = sol.invertTree(root)