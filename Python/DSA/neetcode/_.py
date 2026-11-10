class Solution:
    def removeDuplicates(self, nums: list[int]) -> int:
        n = len(nums)
        if n<2:
            return n
        l = 0
        for r in range(1,n):
            if nums[l]!=nums[r]:
                l+=1
                nums[l]=nums[r]
        print(nums)
        return l+1

if __name__ == "__main__":
    nums = [1,2]
    nums2 = [0,0,1,1,1,2,2,3,3,4]
    print(Solution().removeDuplicates(nums))
    print(Solution().removeDuplicates(nums2))
