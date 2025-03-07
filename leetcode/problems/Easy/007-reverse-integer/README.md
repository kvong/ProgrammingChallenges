# PROBLEM: 
Given a 32-bit signed integer, reverse digits of an integer.

## Example 1:
Input: 123
Output: 321

## Example 2:
Input: -123
Output: -321

## Example 3:
Input: 120
Output: 21

**Note:**
- Assume we are dealing with an environment which could only store integers within the 32-bit signed integer range: [−231, 231 − 1].
- For the purpose of this problem, assume that your function returns 0 when the reversed integer overflows.

## SOLUTION:
1. Check if number is a negative input number.
2. Take the absolute value of the input number.
3. Convert the absolute value from int to a string.
4. Reverse the string.
5. Convert the string back to an int.
6. If the number was originally a negative number change the number to negative.
7. Check if by reversing, we caused an overflow.
8. If overflowed return 0, else return the number.

```python
class Solution:
    def reverse(self, x: int) -> int:
        is_negative = False
        if x < 0:
            is_negative = True
        
        x = str(abs(x))[::-1]
        
        n = int(x)
        
        if is_negative:
            n = int(x) * -1
        
        if abs(n) > (2 ** 31 - 1):
            return 0
        
        return n
