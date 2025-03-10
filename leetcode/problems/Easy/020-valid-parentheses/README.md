# PROBLEM: 
Given a string containing just the characters '(', ')', '{', '}', '[' and ']', determine if the input string is valid.  
An input string is valid if:
- Open brackets must be closed by the same type of brackets.
- Open brackets must be closed in the correct order.
- Note that an empty string is also considered valid.

## Example 1:
Input: "()"  
Output: true

## Example 2:
Input: "()[]{}"  
Output: true

## Example 3:
Input: "(]"  
Output: false

## Example 4:
Input: "([)]"  
Output: false

## Example 5:
Input: "{[]}"  
Output: true

## Solution:
- Create a stack.
- From the first character of the input to the last:
    - If stack is empty, add character to stack.
    - Else, check if the current character counterpart is on the top of the stack.
    - If both characters are corresponding pairs, pop off the top of the stack.
    - Else, add the current character to the top of the stack.
- If in the end the stack is empty then the string was valid, else the string was not valid.

```python
import sys

# Check for corresponding pairs of delimiters
def isPair(opening, closing):
    if opening == '{' and closing == '}':
        return True
    if opening == '[' and closing == ']':
        return True
    if opening == '(' and closing == ')':
        return True
    return False

# Check if delimiters are valid
def isValid(s):
    stack = []
    for char in s:
        if len(stack) == 0:
            stack.append(char)
        else:
            if isPair(stack[len(stack) - 1], char):
                stack.pop()
            else:
                stack.append(char)
    if len(stack) == 0:
        return True
    return False

print(isValid(sys.argv[1]))
