from typing import List


class Solution:
    def rotate(self, matrix):
        length = len(matrix)

        for i in range(length // 2 + length % 2): # add length % 2 to cycle over every element except the last (cause that gets switched at the beginning)
            for j in range(length //2):
                temp = matrix[length - 1 - j][i] # element moving up the left column
                matrix[length - 1 - j][i] = matrix[length - 1 - i][length - j - 1] # element moving left on the bottom
                matrix[length - i - 1][length - j - 1] = matrix[j][length - 1 - i] # the element on the right (moving down)
                matrix[j][length - i - 1] = matrix[i][j]
                matrix[i][j] = temp# element on top, moving left


sol = Solution()
sol.rotate([[1, 2, 3], [4, 5, 6], [7, 8, 9]])
