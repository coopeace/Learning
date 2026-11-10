from typing import List
from collections import deque

class Solution:
    def maxSlidingWindow(self, nums: List[int], k: int) -> List[int]:
        d = deque()
        l = 0
        res = list()
        for r in range(len(nums)):
            # breakpoint()
            while d and nums[d[-1]]<nums[r]:
                d.pop()
            
            d.append(r)

            if r - l + 1 == k :
                res.append(nums[d[0]])
                if d[0]==l:
                    d.popleft()
                l+=1
        return res

if __name__ == "__main__":
    # nums = [1,2,1,0,4,2,6]
    # k = 3
    nums = [7,2,4]
    k = 2
    print(Solution().maxSlidingWindow(nums,k))
