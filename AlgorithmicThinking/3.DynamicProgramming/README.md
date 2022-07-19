# Dynamic Programming

Dynamic programming is an algorithm design approach that optimizes a program's execution. The word programming in its name actually comes from mathematics which means computing. With dynamic programming we can optimize problems where there are *overlapping sub-problems*. 

## Steps to solve:
### 1. Find Optimal Solution
At its core dynamic programming is just a way to solve recursive problems. So the first step is a solution. The tricky part of this is that we can't just find any solution we have to find the Optimal solution. There are cases where we can have multiple solutions, but the question will ask for the best solution. 

The optimal solution is important as it will be the base that we'll need before moving forward. Looking ahead, we know that we'll use recursion so it's obvious that we'll have to establish some sort of base case or termination condition. Whatever the base case is, it should be noted that it must be a clear base case without any discrepancies. For example, supposed we are asked to find the most optimal a person can eat burger *a* and burger *b* within *t* time. A mistake would be to assume `t = 0` to be a base case. While `t = 0` is a terminating state, `t - a = 0` or `t - b = 0` would be the base case since eating *a* *b* leads to the terminal state. If we only have `t = 0`, there's still the discrepacy of which burger we ate to get to this point.

The main take away here is to arrive at a base solution where the truth is definite. This is usually a property of the given problem. This will be a vital part in our Dynamic Programming solution.

### 2. Come up with a Recursive Solution
With a base case established, we can move forward with finding a recursive solution. It can be difficult because we are offsetting the problem to the solution to the next subproblem. A useful tip to prove the correctness of a recursive solution is to try to prove it using induction with the base case being our principal optimal solution (inarguably true). For example, if we are trying to solve *f(x)* but *f(x)* depends on the solution of *f(x-1)*. This is fine, we'll simply keep on subtracting *x* until we reach the termination condition. From there, everything will unravel itself and we'll be able to solve the problem as a whole.

### 3. Implement Memoization on top of Recursive Solution
Although we had established a recursive solution, another problem we'll see is that recursive solutions has a lot of overlaps. To solve the overlapping subproblems of recursion, we'll implement a lookup table. For example, once we are done with solving a subproblem, we'll store it so that the next time we face this problem again, we'll use the memo table for a quick lookup.

With memoization, the number of subproblems we have to solve reduces significantly. In most cases, an exponential timed algorithm will be reduced to linear time.
 
## Top-down vs bottom-up
In steps 1-3 we discussed how to develop a recursive solution and optimize it. Memoization is what's known as a top-down approach. Imagine a binary tree representing our function calls. To get the root solution, we divide the problem into subproblems. It is not until we drill down to the finest subproblem ( the base case ) that we return i.e. move back up the tree. Doing so, we essentially traversed the recursion tree top-down and back up again to get to the root solution.

The top-down approach will optimize our code well enough to achieve linear time but there's another way to achieve the same result (perhaps even faster depending on machine code optimization). Rather than top-down, dynamic programming uses a bottom-up approach. This means that instead of asking how can we arive at an answer, we'll be asking how we can build this answer. To do this, we'll use a loop to build out our solution instead of recursive calls.

### 4. Dynamic Progamming
Observe that when we implement the recursive solution, we are essentrially drilling down to the base case. Thus, if we can drill any of our problem down into a base case, can we not also build up from the base case to arrive at the same solution?

The thoughts behind dynamic programming is the following:
1. Start with the base case.
2. Build off the base case. Because the base case is used to prove all subsequent cases we can conclude that all the subsequent cases will be correct. This idea is similar to the unraveling of the recursion tree after all the subproblems has been solved.
3. With the proven subsequent base cases, we can use our new base cases to go further until we reach the solution we are looking for.

Unlike the recursive solution, where we lookup our previous solutions, the dynamic programming solutions utilizes a look-back approach. This look-back is to get our newly proven base case. Similarly to the memoization lookup, this lookback is also a constant time lookup.
