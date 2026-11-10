#dynamic programming
class Solution:
    def isPalindrome(self,s:str)->bool:
        left,right = 0,len(s)
        while left<right:
            if s[left]!=s[right]:
                return False
            left += 1
            right -= 1
        return True

    def longestPalindrome(self, s: str) -> str:
        if not s or len(s)==1:
            return s
        window = ""
        res = ""
        left = 0
        for right in range(1,len(s)):
            pass
        return res

if __name__ == "__main__":
    s = "babad"
    print(Solution().longestPalindrome(s))
