from typing import List


class Solution:
    def spiralOrder(self, matrix: List[List[int]]) -> List[int]:
        ordered = []
        width = len(matrix[0])
        height = len(matrix)
        left, right, top, bottom = 0, width - 1, 0, height - 1 # set the boundaries of the matrix

        while left < right and top < bottom:
            for i in range(left, right):
                ordered.append(matrix[top][i]) # Go across the top row and get the answer

            for i in range(top, bottom):
                ordered.append(matrix[i][right]) # get the right-most column

            for i in range(right, left, -1): # get the bottom layer
                ordered.append(matrix[bottom][i])

            for i in range(bottom, top, -1): # Get the left column
                ordered.append(matrix[i][left])

            top += 1  # Set the boundaries on the new matrix
            right -= 1
            bottom -= 1
            left += 1

        # This is in case it's a 1xm or nx1 matrix
        if len(ordered) < height*width:
            for row in range(top, bottom+1):
                for col in range(left, right+1):
                    ordered.append(matrix[row][col])

        return ordered



sol = Solution()

print(sol.spiralOrder([[1,2,3],[4,5,6],[7,8,9]]))