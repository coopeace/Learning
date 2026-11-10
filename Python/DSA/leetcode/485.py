from typing import List

class Solution:
    def findMaxConsecutives(self,nums:List[int])->int:
        count=0
        max_count = 0
        for n in nums:
            if n!=1:
                count=0
            else:
                count+=1
                if max_count<count:
                    max_count=count
        return max_count

if __name__ == "__main__":
    nums = [1,1,0,1,1,1]
    print(Solution().findMaxConsecutives(nums))

