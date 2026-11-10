from typing import List
import random

def shuffle(nums:List[int])->List[int]:
    for i in range(len(nums)-1,0,-1):
        j = random.randint(0,i)
        nums[i],nums[j] = nums[j],nums[i] 
    return nums

nums = [28,12,39,22]
print(shuffle(nums))
