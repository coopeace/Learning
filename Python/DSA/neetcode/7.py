from typing import List

class Solution:
    def productExceptSelf(self, nums: List[int]) -> List[int]:
        n = len(nums)
        res = [1]*n
        prefix = 1
        suffix = 1
        left = 0
        right = n - 1
        while left != n and right != -1:
            res[left] *= prefix
            res[right] *= suffix
            prefix *= nums[left]
            suffix *= nums[right]
            left += 1
            right -=1

        return res

    def productExceptSelf3(self, nums: List[int]) -> List[int]:
        res = [1]*len(nums)
        accumlator = 1
        # prefix
        for i in range(len(nums)):
            res[i] = accumlator
            accumlator *= res[i]

        accumlator=1
        # suffix
        for i in range(len(nums)-1,-1,-1):
            res[i] *= accumlator
            accumlator *= res[i]

        return res

    # Brute force O(n^2)
    def productExceptSelf2(self, nums: List[int]) -> List[int]:
        res = list()
        for i in range(len(nums)):
            product = 1
            for j in range(len(nums)):
                if i==j:
                    continue
                product *= nums[j]
            res.append(product)
        return res

if __name__ == "__main__":
    nums = nums=[1,2,4,6]
    print(Solution().productExceptSelf(nums))
