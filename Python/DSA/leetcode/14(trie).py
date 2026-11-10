from typing import List

class Solution:
    def longestCommonPrefix(self,strs:List[str])->str:
        res = ""
        loop = len(strs[0])
        for s in strs:
            if len(s)<loop:
                loop = len(s)
        for i in range(loop):
            ...
        return res

if __name__ == "__main__":
    strs=["flower","flow","flight"]
    print(Solution().longestCommonPrefix(strs))
