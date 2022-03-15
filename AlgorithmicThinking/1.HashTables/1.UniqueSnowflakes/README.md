# Unique Snowflake 

[Link to original content problem](https://dmoj.ca/problem/cco07p2)

## Problem
You may have heard that no two snowflakes are alike. Your task is to write a program to determine whether this is really true. Your program will read information about a collection of snowflakes, and search for a pair that may be identical.

Each snowflake has six arms. For each snowflake, your program will be provided with a measurement of the length of each of the six arms. Any pair of snowflakes which have the same lengths of corresponding arms should be flagged by your program as possibly identical.

## Input
The first line of input will contain a single integer n , 0 < n ≤ 100,000 , the number of snowflakes to follow. This will be followed by n n lines, each describing a snowflake. Each snowflake will be described by a line containing six integers (each integer is at least 0 and less than 10 000 000 , the lengths of the arms of the snowflake. The lengths of the arms will be given in order around the snowflake (either clockwise or counterclockwise), but they may begin with any of the six arms. For example, the same snowflake could be described as `1 2 3 4 5 6` or `4 3 2 1 6 5`.

## Output
If all of the snowflakes are distinct, your program should print the message: `No two snowflakes are alike`.

If there is a pair of possibly identical snowflakes, your program should print the message: `Twin snowflakes found`.

## Running the program
`gcc main.c && ./a.out < test1`

## Test Cases
1. Snowflakes _a_ and _b_ where _a_ and _b_ are `alike`.
2. Snowflakes _a_ and _b_ where _a_ and _b_ are `alike` and _b_ is rotated left/right.
3. Snowflakes _a_ and _b_ where _a_ and _b_ are `alike` and _b_ is flipped vertically/horizontally.
4. Snowflakes _a_ and _b_ where _a_ and _b_ are `alike` and has repeating arms. Example: `0 0 0 0 0 0`, or `0 1 2 2 1 0`
5. Snowflakes _a_ and _b_ where _a_ and _b_ are `not alike`.
6. Snowflakes _a_ and _b_ where _a_ and _b_ are `alike` except one arm.

## Reflection

Originally I was able to solve this problem by simply storing the snowflakes into an array of struct. The idea was to select the first snowflake and compare it to the second (and so on). If the first snowflake unique move on to the second snowflake, from the second snowflake compare it to the third since we have already compared it to the first and found that it was not similar so there's no need to repeat.

### Commparing left and right

While writing the comparison functions, I ran into issues when trying to optimize the comparison. For example, after finding the first similar arm between the current and next snowflake, we can check from there. This did not take into consideration that multiple arms can be the same value.

### Getting a better runtime

Originally the snowflakes were stored in an array as explained above. This lead to an issue where the comparisons were computed as n + ( n - 1 ) + ( n - 2 ) +... = (n( n + 1 ))/2 which comes out to O(n<sup>2</sup>) comparisons which when submitted to the online judge, resulted in going over the time limit.

To reduce the number of comparisons, the book suggested to use a hash table instead. So rather then comparing all the snowflakes, we only compare snowflakes that are in the same goup AND ignore snowflakes that are alone in the group. Implementing the hashtable where the hash is the sum of all the arms greatly reduced the comparison that had to be made. Which got us into a good time range.

### Getting better memory usage

`HASHMOD` was used to adjust the size of the hashtable. Larger table uses more memory but leads to smaller numbers of collision. Low collisions is good because that will help us be more selective of which snowflake can go into a group. However to keep the memory and time at a good level we arrived at 1,000. When `HASHMOD` was set as 100, there were many collisions, which resulted in a high execution time. When `HASHMOD` was set as 10,000 the memory usage was too high. Thus, 1,000 seems to be a good balanced number.


