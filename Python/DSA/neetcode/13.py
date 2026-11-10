from typing import List

class Solution:
    def dailyTemperatures2(self, temperatures: List[int]) -> List[int]:
        n=len(temperatures)
        warmer = [0]*n
        high = [n-1]
        for i in range(n-2,-1,-1):
            while high and temperatures[i]>=temperatures[high[-1]]:
                high.pop()
            if high:
                warmer[i]=high[-1]-i
            high.append(i)
        return warmer

    # O(n square)
    def dailyTemperatures(self, temperatures: List[int]) -> List[int]:
        warmer = [0]*len(temperatures)
        for i in range(len(temperatures)-1,-1,-1):
            found=False
            j = i + 1
            while found!=True:
                if j==len(temperatures):
                    break
                elif temperatures[i]==temperatures[j]:
                    j+=1
                    continue
                elif min(temperatures[i],temperatures[j]) == temperatures[i]:
                    warmer[i] = j-i
                    found=True
                j+=1
        return warmer

if __name__ == "__main__":
    t1 = [30,38,30,36,35,40,28]
    t2 = [22,21,20]
    t3=[89,62,70,58,47,47,46,76,100,70]
    # print("temperat:",t3)
    # print("expected:",[8,1,5,4,3,2,1,1,0,0])
    print("result  :",Solution().dailyTemperatures2(t3))
    # print(Solution().dailyTemperatures(t2))
