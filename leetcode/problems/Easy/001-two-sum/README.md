# PROBLEM: 
Given an array of integers, return indices of the two numbers such that they add up to a specific target.  
You may assume that each input would have exactly one solution, and you may not use the same element twice.

## Example:
Given nums = [2, 7, 11, 15], target = 9,  
Because nums[0] + nums[1] = 2 + 7 = 9,  
return [0, 1].

## Solution:
Using a hash-map:
1. Create an empty hashmap.
2. Loop through the list of numbers.
3. Get the difference between the current number and the target number.
4. If this current number is not in the hashmap, create a new hash with the difference as the key and the index as the value.
5. If this current number is in the hashmap, return the current number index, along with the hash with the current number as the key.
6. Return an empty list if the sum is not found.

### In plain English:
This algorithm uses a hashmap for easy lookup. When we take a look at a number, we first check if this number is in the hash. If the number is not in the hash, we subtract the target by this number and use that difference as the key with the value being this index. The keys in the hashmaps are holding the differences. Hence, these are the target after being subtracted by our number. So then we simply look for the number that we can use to subtract the rest to make 0.

## Code:
```python
class Solution:
    def twoSum(self, nums: List[int], target: int) -> List[int]:
        h_map = {}
        for i, num in enumerate(nums):
            diff = target - num
            if num in h_map:
                return [h_map[num], i]
            h_map[diff] = i
        return []
