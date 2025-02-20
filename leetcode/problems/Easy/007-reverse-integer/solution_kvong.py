
def reverse( x ):
    
    # Check negative
    is_negative = False
    if x < 0:
        is_negative = True
        
    # Reverse
    x = str(abs(x))[::-1]
    
    # To int
    n = int(x)
    # Place negative sign
    if is_negative:
        n = int(x) * -1
        
    # Check overflow
    if(abs(n) > (2 ** 31 - 1)):
        return 0   
    return n


Input = 123
Output = 321

if Output == reverse(Input):
    print("SUCCESS")
    print("Input: ", Input, "Expected: ", Output,  "Output: ", reverse(Input))

Input = -123
Output = -321

if Output == reverse(Input):
    print("SUCCESS")
    print("Input: ", Input, "Expected: ", Output,  "Output: ", reverse(Input))

Input = 120
Output = 21

if Output == reverse(Input):
    print("SUCCESS")
    print("Input: ", Input, "Expected: ", Output,  "Output: ", reverse(Input))
