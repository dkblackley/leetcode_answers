from typing import List


class Solution:
    def maxSubArray(self, nums: List[int]) -> int:

        global_max = nums[0]
        local_max = nums[0] - nums[0] - 1

        for i in range(0, len(nums)):
            local_max = max(nums[i], nums[i] + local_max)
            if local_max > global_max:
                global_max = local_max

        return global_max



sol = Solution()
print(sol.maxSubArray([5,4,-1,7,8]))