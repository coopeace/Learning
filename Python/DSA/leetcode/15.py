class Solution:
    def threeSum(self, nums: list[int]) -> list[list[int]]:
        nums = sorted(nums)
        res = list()
        for i in range(len(nums)):
            if nums[i]>0:
                return res
            if i>0 and nums[i]==nums[i-1]:
                continue

            target = -nums[i]
            left,right = i+1,len(nums)-1
            while left < right:
                total = nums[left]+nums[right]
                if target == total:
                    res.append([nums[i],nums[left],nums[right]])
                    left += 1
                    right -= 1
                    while left < right and nums[left]==nums[left-1]:
                        left+=1
                elif target > total:
                    left += 1
                else :
                    right -= 1
        return res

if __name__ == "__main__":
    nums = [0,1,1]
    nums = [-1,0,1,2,-1,-4]
    nums = [-100,-70,-60,110,120,130,160]
    nums = [1,2,0,1,0,0,0,0]
    print(Solution().threeSum(nums))
