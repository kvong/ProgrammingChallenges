**74. Search a 2D Matrix**

You are given an `m x n` integer matrix `matrix` with the following two properties:

- Each row is sorted in non-decreasing order.
- The first integer of each row is greater than the last integer of the previous row.

Given an integer `target`, return `true` _if_ `target` _is in_ `matrix` _or_ `false` _otherwise_.  
You must write a solution in `O(log(m * n))` time complexity.

**Example 1:**
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 3
Output: true
```

**Example 2:**
```
Input: matrix = [[1,3,5,7],[10,11,16,20],[23,30,34,60]], target = 13
Output: false
```

**Solution**
```python
class Solution:
    def searchMatrix(self, matrix: List[List[int]], target: int) -> bool:
        # Do binary search on the first item of every row
        cols = len(matrix[0])
        rows = len(matrix)

        bl = 0
        br = cols * rows - 1

        while bl <= br:
            m = ( bl + br ) // 2
            m_i = m // cols
            m_j = m % cols

            m_num = matrix[m_i][m_j]
            if m_num < target:
                bl = m + 1
            elif m_num > target:
                br = m - 1
            else:
                return True
        return False

