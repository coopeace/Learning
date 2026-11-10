from typing import List

class Solution:
    def characterReplacement(self, s: str, k: int) -> int:
        if len(s)==1:
            return 1
        left,right = 0,0
        max_freq,max_win=0,0
        counter=dict()
        for right in range(len(s)):
            counter[s[right]] = counter.get(s[right],0)+1
            max_freq = max(max_freq,counter[s[right]])

            if right-left+1 - max_freq > k:
                counter[s[left]]-=1
                left+=1

            max_win = max(max_win,right-left+1)
        return max_win

if __name__ == "__main__":
    # s = "XYYX"
    # k = 2
    s="AAABABB"
    k=1
    # s="ABBB"
    # k=2
    s="AAAAABBBBCBB"
    k=3
    print(Solution().characterReplacement(s,k))
