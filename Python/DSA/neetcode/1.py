from typing import Counter, List

class Solution:
    #runtime 32ms
    def hasDuplicate(self, nums: List[int]) -> bool:
        track = set()
        for n in nums:
            if n in track:
                return True
            else :
                track.add(n)
        return False
    
    #runtime 32ms
    def hasDuplicate2(self, nums: List[int]) -> bool:
        s = set(nums)
        return len(s) != len(nums)

if __name__ == "__main__":
    nums = [2,3,5,6]
    print(Solution().hasDuplicate(nums))
