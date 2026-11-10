from typing import List

class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        res = list()
        nums = sorted(nums)
        for i in range(len(nums)-2):
            if nums[i] > 0:
                break
            if i > 0 and nums[i] == nums[i - 1]:
                continue
            target = -nums[i]
            left,right = i+1,len(nums)-1
            while left < right:
                add = nums[left]+nums[right]
                if add == target:
                    res.append([nums[i],nums[left],nums[right]])
                    left+=1
                    right-=1
                    while left < right and nums[left] == nums[left - 1]:
                        left += 1
                elif add > target:
                    right-=1
                else :
                    left += 1
        return res

if __name__ == "__main__":
    nums = [-1,0,1,2,-1,-4]
    nums2 = [0,1,1]
    nums3=[-2,0,1,1,2]
    # print(Solution().threeSum(nums))
    # print(Solution().threeSum(nums2))
    print(Solution().threeSum(nums3))
