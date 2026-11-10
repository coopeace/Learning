class Solution:
    def lengthOfLongestSubstring(self, s: str) -> int:
        res = 0
        seen = set()
        l=0
        for r,ch in enumerate(s):
            if ch in seen:
                seen.remove(ch)
                l+=1
            else:
                seen.add(ch)
                if r-l > res:
                    res=r-l
        return res


if __name__ == "__main__":
    s = "abcabcbb"
    print(Solution().lengthOfLongestSubstring(s))
