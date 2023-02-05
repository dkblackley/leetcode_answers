from typing import List


class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        hash_map = {}

        for i in range(len(nums)):
            if (target - nums[i]) in hash_map.keys():
                return [i, hash_map[target - nums[i]]]
            hash_map[nums[i]] = i


sol = Solution()

print(sol.twoSum([2,7,11,15], 9))