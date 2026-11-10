from typing import List

class Solution:
    def longestConsecutive(self, nums: List[int]) -> int:
        consecutive = set(nums)
        longest = 0
        for n in nums:
            if n-1 not in consecutive:
                count = 1 
                while n+1 in consecutive:
                    count += 1
                    n += 1
                if count > longest:
                    longest = count

        return longest

if __name__ == "__main__":
    # nums = [2,20,4,10,3,4,5]
    nums1 = [0,3,2,5,4,6,1,1]
    nums=[9,1,4,7,3,-1,0,5,8,-1,6]
    nums2 = [1, 2, 100, 101, 102]
    print(Solution().longestConsecutive(nums))
    print(Solution().longestConsecutive(nums2))
