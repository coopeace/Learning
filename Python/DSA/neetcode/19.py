from typing import List

class Solution:
    def maxArea(self, heights: List[int]) -> int:
        max_area = 0
        c_area = 0
        l,r = 0,len(heights)-1
        while l < r:
            if heights[l] < heights[r]:
                c_area = heights[l]*(r-l)
            else :
                c_area = heights[r]*(r-l)
            if c_area > max_area:
                max_area = c_area
            if heights[l] < heights[r]:
                l+=1
            else :
                r-=1
        return max_area

if __name__ == "__main__":
    height = [1,7,2,5,4,7,3,6]
    print(Solution().maxArea(height))
