from typing import List

class Solution:
    def largestRectangleArea(self,heights : List[int])->int:
        stack = list()
        largest_area = 0
        for i in range(len(heights)):
            while stack and heights[stack[-1]]>heights[i]:
                h = heights[stack.pop()]
                w = i if not stack else i-stack[-1]-1
                largest_area = max(largest_area,h*w)
            stack.append(i)
        while stack:
            h = heights[stack.pop()]
            w = len(heights) if not stack else len(heights)-stack[-1]-1
            largest_area = max(largest_area,h*w)
        return largest_area

if __name__ == "__main__":
    heights = [7,1,7,2,2,4]
    heights2 = [1,3,7]
    heights3 = [2,1,5,6,2,3]
    heights4 = [5,4,1,2]
    heights5=[1,2,3,4,5]
    print(Solution().largestRectangleArea(heights))
    print(Solution().largestRectangleArea(heights2))
    print(Solution().largestRectangleArea(heights3))
    print(Solution().largestRectangleArea(heights4))
    print(Solution().largestRectangleArea(heights5))
