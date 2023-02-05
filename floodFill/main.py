from typing import List


class Solution:

    starting_colour = 0
    color = -99999999999999999999999

    def floodFill(self, image: List[List[int]], sr: int, sc: int, color: int) -> List[List[int]]:
        self.starting_colour = image[sr][sc]
        #self.color = color
        image =  self.recursive_fill(image, sr, sc)

        for i in range(0, len(image)):
            for j in range(0, len(image[i])):
                if image[i][j] == self.color:
                    image[i][j] = color

        return image

    def recursive_fill(self, image: List[List[int]], sr: int, sc: int) -> List[List[int]]:

        if  sr < len(image) and sc < len(image[sr]) and image[sr][sc] == self.starting_colour and sr >= 0 and sc >= 0:
            image[sr][sc] = self.color

            image = self.recursive_fill(image, sr + 1, sc)  # move down
            image = self.recursive_fill(image, sr, sc + 1)  # move right

            image = self.recursive_fill(image, sr - 1, sc)  # move up
            image = self.recursive_fill(image, sr, sc - 1)  # move left


        return image


sol = Solution()
#print(sol.floodFill([[1,1,1],[1,1,0],[1,0,1]], 1, 1, 2))
print(sol.floodFill([[0,0,0],[0,0,0]], 0, 0, 0))