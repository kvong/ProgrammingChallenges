import unittest

def identical_left(snow1, snow2, start):
    for offset in range(len(snow1)):
        snow2_index = start - offset
        if snow2_index < 0:
            snow2_index += 6
        if snow1[offset] != snow2[snow2_index]:
            return False
    return True

def identical_right(snow1, snow2, start):
    for offset in range(len(snow1)):
        snow2_index = start + offset
        if snow2_index > 5:
            snow2_index -= 6
        if snow1[offset] != snow2[snow2_index]:
            return False
    return True

def are_identical(snow1, snow2):
    for i in range(len(snow1)):
        if identical_left(snow1,snow2,i):
            return True
        if identical_right(snow1,snow2,i):
            return True
    return False

def identify_identical(snowflakes):
    for i in snowflakes.keys():
        for j in range(len(snowflakes[i])):
            for k in snowflakes[i][j+1:]:
                if are_identical(snowflakes[i][j],k):
                    print('Snowflakes found')
                    return
    print('Snowflakes not found')



snowflakes = {
1 : [[1,2,3,4,5,6], [6,5,4,3,2,1]], # identical
2 : [[1,2,1,3,1,2], [1,2,3,1,2,3]],
3 : [[1,2,3,3,2,1], [2,3,3,2,1,1]]  # identical
}

identify_identical( snowflakes )
