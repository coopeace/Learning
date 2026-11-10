from typing import List

class Solution:
    def trap(self, height: List[int]) -> int:
        res = 0
        left, right = 0, len(height) - 1
        leftMax, rightMax = 0, 0
        while left < right:
            if height[left] < height[right]:
                if height[left] >= leftMax:
                    leftMax = height[left]
                else:
                    res += leftMax - height[left]
                left += 1
            else:
                if height[right] >= rightMax:
                    rightMax = height[right]
                else:
                    res += rightMax - height[right]
                right -= 1
        return res

    def trap2(self, height: List[int]) -> int:
        res = 0
        left,right = 0, len(height) -1
        leftMax = 0
        rightMax = 0
        while left < right:
            leftMax = max(leftMax,height[left])
            rightMax = max(rightMax,height[right])
            if leftMax < rightMax:
                res += leftMax - height[left]
            else :
                res += rightMax - height[right]
            if leftMax < rightMax:
                left+=1
            else :
                right-=1
        return res

if __name__ == "__main__":
    height = [0,2,0,3,1,0,1,3,2,1]
    print(Solution().trap(height))
