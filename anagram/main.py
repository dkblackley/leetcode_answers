class Solution:
    def isAnagram(self, s: str, t: str) -> bool:
        dict = {}
        for character in s:
            if character in dict.keys():
                dict[character] += 1
            else:
                dict[character] = 0

        for character in t:
            if character in dict.keys():
                if dict[character] == 0:
                    del dict[character]
                else:
                    dict[character] -= 1
            else:
                return False

        return not bool(dict)



sol = Solution()

print(sol.isAnagram("cat", "rat"))