```python
class Solution(object):
    def lengthOfLongestSubstring(self, s):
        """
        :type s: str
        :rtype: int
        """
        if not s:
            return 0
        
        l = 0
        r = 1
        longest_len = 1
        
        while r < len(s):
            if s[r] in s[l:r] and l < r:
                l += 1
            else:
                if longest_len < len(s[l:r+1]):
                    longest_len = len(s[l:r+1])
                r += 1
        
        return longest_len
