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
