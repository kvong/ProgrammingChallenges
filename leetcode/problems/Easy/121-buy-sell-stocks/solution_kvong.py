class Solution:
    def maxProfit(self, prices: List[int]) -> int:
        if len(prices) == 0:
            return 0
        l = 0
        r = 1

        result = 0
        while r < len(prices):
            if prices[r] >= prices[l]:
                result = max( result, prices[r] - prices[l] )
            else:
                l = r
            r += 1
        return result
