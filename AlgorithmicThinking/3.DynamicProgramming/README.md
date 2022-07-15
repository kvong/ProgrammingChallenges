# Dynamic Programming

Dynamic programming is an algorithm design approach that optimizes a program's execution. The word programming in its name actually comes from mathematics which means computing. With dynamic programming we can optimize problems where there are *overlapping sub-problems*. 

## Steps to solve:
### 1. Find Optimal Solution
At its core dynamic programming is just a way to solve recursive problems. So the first step is a solution. The tricky part of this is that we can't just find any solution we have to find the Optimal solution. There are cases where we can have multiple solutions, but the question will ask for the best solution. 

The optimal solution is important as it will be the base that we'll need before moving forward. Looking ahead, we know that we'll use recursion so it's obvious that we'll have to establish some sort of base case or termination condition. Whatever the base case is, it should be noted that it must be a clear base case without any discrepancies. For example, supposed we are asked to find the most optimal a person can eat burger *a* and burger *b* within *t* time. A mistake would be to assume `t = 0` to be a base case. While `t = 0` is a terminating state, `t - a = 0` or `t - b = 0` would be the base case since eating *a* *b* leads to the terminal state. If we only have `t = 0`, there's still the discrepacy of which burger we ate to get to this point.

The main take away here is to arrive at a base solution where the truth is definite. This is usually a property of the given problem. This will be a vital part in our Dynamic Programming solution.

### 2. Come up with a Recursive Solution
With a base case established, we can move forward with finding a recursive solution. It can be difficult because we are offsetting the problem to the solution to the next subproblem. A useful tip to prove the correctness of a recursive solution is to try to prove it using induction with the base case being our optimal solution above. For example, if we are trying to solve *f(x)* but *f(x)* depends on the solution of *f(x-1)*. This is find, we'll simply keep on subtracting *x* until we reach the termination condition we established while finding the Optimal Solution. From there, everything will unravel itself and we'll be able to solve the whole problem.

### 3. Implement Memoization on top of Recursive Solution
 
### 4. Dynamic Progamming

## Top-down vs bottom-up
