from typing import List


class Solution:
    def search(self, nums: List[int], target: int) -> int:

        if not nums:
            return -1

        index = int(len(nums)/2)
        n = nums[index]

        if n == target:
            return index
        if n > target:
            temp = self.search(nums[:index], target)
            if temp != -1:
                return temp
            else:
                return -1
        else:
            temp = self.search(nums[index + 1:], target)
            if temp != -1:
                return temp + index + 1
            else:
                return -1







sol = Solution()

print(sol.search([-1,0,3,5,9,12],))