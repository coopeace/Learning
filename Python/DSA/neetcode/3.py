from typing import Counter, List

class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        return []

    
    # runtime 56ms
    def twoSum2(self, nums: List[int], target: int) -> List[int]:
        for i in range(len(nums)):
            for j in range(i+1,len(nums)):
                sum = nums[i] + nums[j]
                if sum == target:
                    return [i,j]
        return []

if __name__ == "__main__":
    nums = [[3,4,5,6],[4,5,6],[5,5]]
    targets =[7,10,10]
    for i in range(len(nums)):
        print(f"s={nums[i]},t={targets[i]}")
        print(f"Result:{Solution().twoSum(nums[i],targets[i])}")
