# 15. 3Sum

## Problem

Given an integer array `nums`, return all the triplets `[nums[i], nums[j], nums[k]]` such that `i != j`, `i != k`, and `j != k`, and `nums[i] + nums[j] + nums[k] == 0`. Notice that the solution set must not contain duplicate triplets.

**Example 1:**
```
Input: nums = [-1,0,1,2,-1,-4]
Output: [[-1,-1,2],[-1,0,1]]
Explanation: 
nums[0] + nums[1] + nums[2] = (-1) + 0 + 1 = 0.
nums[1] + nums[2] + nums[4] = 0 + 1 + (-1) = 0.
nums[0] + nums[3] + nums[4] = (-1) + 2 + (-1) = 0.
The distinct triplets are [-1,0,1] and [-1,-1,2].
Notice that the order of the output and the order of the triplets does not matter.
```

**Example 2:**
```
Input: nums = [0,1,1]
Output: []
Explanation: The only possible triplet does not sum up to 0.
```

**Example 3:**
```
Input: nums = [0,0,0]
Output: [[0,0,0]]
Explanation: The only possible triplet sums up to 0.
```

## Solution - sliding window
```python
class Solution:
    def threeSum(self, nums: List[int]) -> List[List[int]]:
        nums.sort()
        res = []
        for i in range(len(nums)):
            if i > 0 and nums[i] == nums[i-1]:
                continue
            l = i + 1
            r = len(nums) - 1
            while l < r:
                if nums[i] + nums[l] + nums[r] < 0 :
                    l += 1
                elif nums[i] + nums[l] + nums[r] > 0:
                    r -= 1
                else:
                    res.append([nums[i], nums[l], nums[r]])    
                    l += 1
                    while nums[l] == nums[l-1] and l < r:
                        l += 1
        return res
```

## Notes
First pointer = i
Second pointer = l
Third pointer = r

**How can we take care of duplicate triplets?**
First pointer will go through all nums. Second pointer will be the one that takes care of the duplicates. The inner loop that goes through the Second and Third pointer will be the one taking care of the duplicates. This works because the array is sorted and the Second and Third will be in pairs. 
- It is important to note that once we get to the second loop, the First pointer is already set. With only the Second and Third pointer in a sorted array, checking for duplicates on the third loop (by moving the second pointer) eliminate the possibility of a third pointer.
- A common mistake is not moving the Second pointer immediately after we append the result. Since we are looking back to see if we've used this number already, it wouldn't make sense to not move the pointer especially since we have already added it to the result list. We move the pointer up one, then check if this one was the number we used previously.

**Why are we looking back instead of looking ahead when checking for duplicates?**
We can use lookahead but looking back is better because we dont have to check for the out of bound range before we do the comparison. While we are still check that the Second and Third pointer havent meet, this is more so that we can continue moving up the left pointer to find other numbers that can fit into the sum.

*Why the for, while, while? Why not while, while, while?*
The advantage of the for that it does the bound check for us. Additionally, we don't have any special login with the First pointer other than moving it forward. If we've already used this number previously, continue to move it forward. We can used while, while, while but that just means more code to for the bound and incrementing the First pointer.

