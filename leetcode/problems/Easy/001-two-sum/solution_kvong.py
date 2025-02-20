nums = [2, 7, 11, 15]

target = 9

expected =  [0, 1]


def twoSum(nums, target):
    h_map = {}
    for i, num in enumerate(nums):
        diff = target - num
        if num in h_map:
            return [h_map[num], i]
        h_map[diff] = i
    return []


print("Expected: ", expected)
print("Output: ", twoSum(nums, target))
