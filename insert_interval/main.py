from typing import List


class Solution:

    def insert(self, intervals: List[List[int]], newInterval: List[int]) -> List[List[int]]:
        """
        First, find out where inside the list the interval sits. Then cycle through the list, checking if the next
        intervals start is before the current intervals end. if it is, replace the current intervals end with the next
        intervals end, then repeat this until you reach the end of the list. Check edge cases where interval is at end or
        beginning.
        :param intervals:
        :param newInterval:
        :return:
        """

        if not intervals:
            return [newInterval]

        for i in range(0, len(intervals)):

            if i == len(intervals) - 1: # if the interval isn't in the array
                intervals.insert(i+1, newInterval)
                break

            if i == 0 and newInterval[0] < intervals[0][0]: # if the new interval is the first value
                intervals.insert(0, newInterval)
                break

            if intervals[i][0] < newInterval[0] and intervals[i+1][0] > newInterval[0]:
                intervals.insert(i+1, newInterval)
                break

        # Now check if the intervals need to be merged
        i = 0
        while i < len(intervals) - 1:

            if intervals[i][1] >= intervals[i+1][0]: # if the next interval overlaps
                if intervals[i][0] > intervals[i+1][0]:
                    intervals[i][0] = intervals[i+1][0]

                if intervals[i][1] < intervals[i+1][1]:
                    intervals[i][1] = intervals[i+1][1]
                del intervals[i+1]
            else:
                i += 1
        return intervals


sol = Solution()
print(sol.insert([[1,5]], [0, 0]))