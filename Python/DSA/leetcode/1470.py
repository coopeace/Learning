from typing import List

class Solution:
    def shuffle(self,nums:List[int],n:int)->List[int]:
        m = 1024
        for i in range(2*n):
            if i%2==0:
                nums[i]+=(nums[i//2]%m)*m
            else:
                nums[i]+=(nums[n+i//2]%m)*m
        for i in range(2*n):
            nums[i]//=m
        return nums

    def shuffle2(self,nums:List[int],n:int)->List[int]:
        res = [0]*(2*n)
        for i in range(n):
            res[2*i]=nums[i]
            res[2*i+1]=nums[n+i]
        return res

if __name__ == "__main__":
    nums = [2,5,1,3,4,7]
    n = 3
    nums = [1,1000,1,1000]
    n = 2
    print(Solution().shuffle(nums,n))
