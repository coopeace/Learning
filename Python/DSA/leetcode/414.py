from typing import List

class Solution:
    def thirdMax2(self, nums: list[int]) -> int:
        nums.sort(reverse=True)
        if len(nums)<3:
            return nums[0]
        c = 1
        for i in range(1,len(nums)):
            if nums[i] != nums[i-1]:
                c+=1
            if c==3 :
                return nums[i]
        return nums[0]

    def thirdMax(self, nums: list[int]) -> int:
        first = float("-inf")
        second = float("-inf")
        third = float("-inf")

        for n in nums:
            if n == first or n == second or n == third:
                continue
            if n > first:
                third = second
                second = first
                first = n
            elif n > second:
                third = second
                second = n
            elif n > third:
                third = n
        return int(third if third!=float("-inf") else first)

if __name__=="__main__":
    nums = [3,34,90,23]
    print(Solution().thirdMax(nums))
