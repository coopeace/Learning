from typing import Counter, List

class Solution:
    # runntime 48ms
    def isAnagram(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        seen = {}
        for ch in s:
            if ch in seen:
                seen[ch] += 1
            else :
                seen[ch] = 1

        for ch in t:
            if seen.get(ch,0) == 0:
                return False
            seen[ch] -= 1
        return True 

    # runntime = 61 ms
    def isAnagram2(self, s: str, t: str) -> bool:
        if len(s) != len(t):
            return False
        return Counter(s) == Counter(t)

if __name__ == "__main__":
    s = ["racecar","jar","x"]
    t = ["carrace","jam","x"]
    for i in range(len(s)):
        print(f"s:{s[i]},t:{t[i]}")
        print(f"Result:{Solution().isAnagram(s[i],t[i])} ")
