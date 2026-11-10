class Solution:
    def moveZeroes2(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        l=0
        for r in range(len(nums)):
            if nums[r]!=0:
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
        print(nums)
    def moveZeroes(self, nums: list[int]) -> None:
        """
        Do not return anything, modify nums in-place instead.
        """
        n = len(nums)
        if n<2:
            return nums
        l,r = 0,1
        while r < n:
            while l < len(nums) and nums[l]!=0:
                l+=1
                r+=1
            while r<n and nums[l]==0 and nums[r]!=0:
                nums[l],nums[r]=nums[r],nums[l]
                l+=1
            r+=1
        print(nums)

if __name__ == "__main__":
    # nums = [0,1,0,3,12]
    nums = [1,2,3]
    # nums = [4, 2, 4, 0, 0, 3, 0, 5, 1, 0]
    Solution().moveZeroes(nums)
