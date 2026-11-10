from typing import List

class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        left,right = 0,1
        profit = 0
        while right < len(prices):
            if prices[left] < prices[right]:
                c_profit = prices[right] - prices[left]
                profit = max(c_profit,profit)
            else:
                left = right
            right += 1
        return profit

if __name__ == "__main__":
    # prices=[5,1,5,6,7,1,10]

    prices=[7,1,5,3,6,4]
    print(Solution().maxProfit(prices))
