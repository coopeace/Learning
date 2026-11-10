from typing import List

class Solution:
    def findMedianSortedArrays(self,nums1:List[int],nums2:List[int])->float:
        merged = sorted(nums1+nums2)
        n = len(merged)
        mid = int(n/2)-1
        if n%2 != 0:
            # breakpoint()
            return float(merged[mid+1])
        else :
            return (merged[mid]+merged[mid+1])/2
        return 0.0

if __name__ == "__main__":
    nums1,nums2 = [],[1]
    print(Solution().findMedianSortedArrays(nums1,nums2))
