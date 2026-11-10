from typing import List

class Solution:
    def removeDuplicates(self,nums:List[int])->int:
        l=0
        for n in nums:
            if l<2 or n!=nums[l-2]:
                nums[l]=n
                l+=1
        print(nums)
        return l

    def removeDuplicates2(self,nums:List[int])->int:
        l = 0
        duplicate = False
        for r in range(1,len(nums)):
            if nums[l]!=nums[r]:
                l+=1
                nums[l]=nums[r]
                duplicate = False
            elif not duplicate:
                l+=1
                nums[l]=nums[r]
                duplicate = True
        return l+1

if __name__ == "__main__":
    nums = [0,0,1,1,1,1,2,3,3]
    # nums = [1,1,1,2,2,3]
    print(Solution().removeDuplicates(nums))
