from typing import List


class Solution:
    # Possible DP Solution: jump into a number and recursively try to make it to the end via biggest then smallest jump
    # If that index couldn't make it to the jump, replace the visitted index with a 0?
    def canJump(self, nums: List[int]) -> bool:

        last_position = len(nums) - 1 # Just hold the last position that could get to the end

        for i in range(len(nums) - 2, -1, -1):
            if (i + nums[i] >= last_position): # If this index can make it to the last position
                last_position = i

        return last_position == 0






sol = Solution()

print(sol.canJump([2,3,1,1,4]))
print(sol.canJump([3,2,1,0,4]))
print(sol.canJump([0]))