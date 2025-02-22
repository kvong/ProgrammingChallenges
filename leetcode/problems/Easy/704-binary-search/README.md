# 704. Binary Search

## Problem

**You are given an array of distinct integers** `nums`, **sorted in ascending order, and an integer** `target`.  
**Implement a function to search for** `target` **within** `nums`. **If it exists, then return its index, otherwise, return** `-1`.  
**Your solution must run in O(log n) time.**

**Example 1:**
```
Input: nums = [-1,0,2,4,6,8], target = 4
Output: 3
```

**Example 2:**
```
Input: nums = [-1,0,2,4,6,8], target = 3
Output: -1
```

## Solution
```python
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
```
