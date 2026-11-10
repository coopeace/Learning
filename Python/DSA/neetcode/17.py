from typing import List

class Solution:
    def twoSum(self,numbers: List[int],target: int)-> List[int]:
        left = 0
        right = len(numbers)-1
        while left < right:
            current_sum = numbers[left] + numbers[right]

            if current_sum == target:
                return [left,right]
            elif current_sum > target :
                right -= 1
            else:
                left += 1
        return []

if __name__ == "__main__":
    numbers = [1,2,3,4]
    target = 3
    print(Solution().twoSum(numbers,target))
