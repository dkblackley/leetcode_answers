class Solution:
    def isPalindrome(self, s: str) -> bool:
        i = 0
        j = len(s) - 1

        while (i < j):
            if s[i] == ' ' or not s[i].isalnum():
                i += 1
                continue
            elif s[j] == ' ' or not s[j].isalnum():
                j -= 1
                continue
            else:
                if s[i].lower() != s[j].lower():
                    return False
            i += 1
            j -= 1

        return True

sol = Solution()
print(sol.isPalindrome("A man, a plan, a canal: Panama"))