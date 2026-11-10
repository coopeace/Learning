nums = [23,46,78,69,91,99,11]
n = len(nums)
for i in range(n//2):
    nums[i],nums[n-1-i]=nums[n-i-1],nums[i]
print(nums) 
