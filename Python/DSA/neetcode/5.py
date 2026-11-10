from typing import List

class Solution:
    # runtime 191
    def topKFrequent(self, nums: List[int], k: int) -> List[int]:
        res = list()
        counter = dict()
        for n in nums:
            counter[n] = 1 + counter.get(n,0)

        buckets = [ [] for i in range(len(nums)+1)]

        for key,count in counter.items():
            buckets[count].append(key)

        for i in range(len(buckets)-1,-1,-1):
            for item in buckets[i]:
                res.append(item)
                if len(res) == k:
                    return res
        return []


    #runtime 310ms
    def topKFrequent2(self, nums: List[int], k: int) -> List[int]:
        counter = dict()
        for n in nums:
            if counter.get(n,0) == 0:
                counter[n] = 1
            else:
                counter[n] += 1
        f = [ [value,key] for key,value in counter.items()]
        f.sort(reverse=True)
        s = f[:k]
        return [s[i][1] for i in range(len(s))]
        

    # runtime 194 ms
    def topKFrequent1(self, nums: List[int], k: int) -> List[int]:
        counter = dict()
        res = list()
        for n in nums:
            if counter.get(n,0) == 0:
                counter[n] = 1
            else:
                counter[n] += 1
        
        f = list(set(counter.values()))
        f.sort(reverse=True)
        t = 0
        duplicate = counter.copy()
        for i in f:
            if t == k:
                return res
            for key,value in counter.items():
                val = duplicate.get(key,0)
                if val == i and val != 0:
                    res.append(key)
                    duplicate.pop(key)

        return res

if __name__ == "__main__":
    nums=[1,2,2,3,3,3]
    k=2
    # nums=[1,2]
    # k=2
    print(Solution().topKFrequent(nums,k))
