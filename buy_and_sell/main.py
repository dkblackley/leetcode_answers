from typing import List


class Solution:
    def maxProfit(self, prices: List[int]) -> int:

        if not prices:
            return 0

        max = 0
        min = prices[0]

        for i in prices:

            if i - min > max:
                max = i - min
            if i < min:
                min = i

        return max

sol = Solution()
print(sol.maxProfit([7,1,5,3,6,4]))
print(sol.maxProfit([7,6,4,3,1]))