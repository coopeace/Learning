from typing import List

class Solution:
    # optimized
    def groupAnagrams(self, strs: List[str]) -> List[List[str]]:
        ans = {}
        
        for s in strs:
            count = [0] * 26
            for c in s:
                count[ord(c) - ord('a')] += 1

            # The tuple is our immutable key
            key = tuple(count)
            
            if key in ans:
                ans[key].append(s)
            else:
                ans[key] = [s]
                
        return list(ans.values())

    # runtime 127
    def groupAnagrams2(self, strs: List[str]) -> List[List[str]]:
        seen = dict()
        for s in strs:
            t = sorted(s)
            t = "".join(t)
            res = seen.get(t,None)
            if res != None:
                res.append(s)
            else:
                seen[t] = [s]
        return list(seen.values())

if __name__ == "__main__":
    strs = ["act","pots","tops","cat","stop","hat"]
    # [["hat"],["act", "cat"],["stop", "pots", "tops"]]
    print(Solution().groupAnagrams(strs))
