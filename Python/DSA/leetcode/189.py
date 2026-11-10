from typing import List

class Solution:
    def reverse(self,nums:List[int],l:int,r:int)->None:
        while l<r:
            nums[l],nums[r-1]=nums[r-1],nums[l]
            l+=1
            r-=1

    def rotate(self,nums:List[int],k:int)->List[int]:
        k%=len(nums)
        self.reverse(nums,0,len(nums))
        self.reverse(nums,0,k)
        self.reverse(nums,k,len(nums))
        return nums

if __name__ == "__main__":
    nums = [1,2,3,4,5,6,7]
    k = 3
    print(Solution().rotate(nums,k))
