from typing import List

class Solution:
    def carFleet(self, target: int, position: List[int], speed: List[int]) -> int:
        pair = [(position[i],speed[i]) for i in range(len(position))]
        # pair = list(zip(position,speed))
        pair = sorted(pair,key=lambda x:x[0],reverse=True)
        fleet = list()
        for p in pair:
            time=(target-p[0])/p[1]
            fleet.append(time)
            if len(fleet)>2 and fleet[-1] <= fleet[-2]:
                fleet.pop()
        return len(fleet)

    def CarFleet2(self,target:int,position:List[int],speed:List[int])->int:
        pair = [(position[i],speed[i]) for i in range(len(position))]
        pair = sorted(pair,key=lambda x : x[0],reverse=True)
        time = [(target-p[0])/p[1] for p in pair]
        fleet = 0
        prev_time = 0
        for t in time:
            if t > prev_time:
                fleet+=1
                prev_time=t
        return fleet

if __name__ == "__main__":
    target=10
    position=[0,4,2]
    speed=[2,1,3]
    print(Solution().carFleet(target,position,speed))
