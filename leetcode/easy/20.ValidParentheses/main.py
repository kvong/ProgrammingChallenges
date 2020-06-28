import sys

# Check for coresponding pairs of delimiters
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
