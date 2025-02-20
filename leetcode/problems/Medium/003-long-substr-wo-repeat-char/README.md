# 3. Longest Substring Without Repeating Characters

Given a string `s`, find the length of the longest substring without duplicate characters.

## Example 1:
Input: s = "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.

## Example 2:
Input: s = "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.

## Example 3:
Input: s = "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3. Notice that the answer must be a substring, "pwke" is a subsequence and not a substring.

# Solution

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
