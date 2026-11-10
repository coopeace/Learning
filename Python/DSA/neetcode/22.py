from typing import List

class Solution:
    def lengthOfLongestSubstring(self,s : str)->int:
        if len(s)==1:
            return 1
        seen = set()
        left,right = 0,0
        max_l = 0
        while right<len(s):
            while s[right] in seen:
                seen.remove(s[left])
                left+=1
            seen.add(s[right])
            right+=1
            if len(seen)>max_l:
                max_l = len(seen)
        print(seen)
        return max_l


if __name__ == "__main__":
    s = "zxyzxyz"
    s="pwwkew"
    s="a b c d"
    print(Solution().lengthOfLongestSubstring(s))
