from typing import List
class Solution:

    def encode(self, strs: List[str]) -> str:
        s = ":#&10*".join(strs)
        return s

    def decode(self, s: str) -> List[str]:
        return s.split(':#&10*')

if __name__ == "__main__":
    strs = ["Hello","World"]
    s = Solution().encode(strs)
    print(Solution().decode(s))
