class Solution:
    def search(self, nums: List[int], target: int) -> int:
        front = 0
        back = len(nums) - 1
        while front <= back:
            m = ( front + back ) // 2
            if nums[m] > target:
                back = m - 1
            elif nums[m] < target:
                front = m + 1
            else:
                return m
        return -1
