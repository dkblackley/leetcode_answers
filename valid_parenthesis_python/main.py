class Solution:
    def isValid(self, s: str) -> bool:
        stack = []
        chars = {']': '[', '}': '{', ')': '('}

        for char in s:
            if char in chars.keys():
                if not stack or chars[char] != stack.pop():
                    return False
            else:
                stack.append(char)

        if stack:
            return False
        else:
            return True

sol = Solution()
print(sol.isValid(')'))