# Burger Fervor

## The Problem
A man named Homer Simpson likes to eat and drink. He has *t* minutes that he'll spend eating burgers and drinking beer. There are two kinds o fburgers. One of them takes *m* minutes to eat, and the other takes *n* minutes to eat.
    Homer likes burgers more than beer, so he'd like to spend the entire *t* minutes eating burgers. However, doing so isn't always possible. For example, if *m* = 4, *n* = 9, and *t* = 15, then no combination of the 4-minute and 9-minute burgers can take him exactly 15 minutes to eat. If that's the case, he'll spend as much time as possible eating burgers and then fill the rest of the time drinking beer. Our task is to determine the number of burgers that Homer can eat.
    
## Input
We reat test cases until there is not more input. Each test case is represented by a line of three integers: *m*, the number of minutes it takes to eat the first kind of burger; *n*, the number of minutes it takes to eat the second kind of burger; and *t*, the number of minutes that Homer will espend eating burgers and drinking beer. Each *m*, *n*, and *t* value is less than 10,000.

## Output
For each testcase:
- If HOmer can spend exactly *t* minutes eating burgers, then output the maximum number of burgers that he can eat.
- Otherwise, output the maximum number of burgers that Homer can eat when maximizing his time eating burgers, a space, and the number of remaining minutes (during which he'll drink beer).

### Test cases
```
4 9 22 -> 3
4 9 15 -> 2 2
4 9 54 -> 11
4 2 88 -> 44
4 2 90 -> 45
```

### Progress:
- [ x ] Implement Recursive Solution
- [ x ] Implement Memoization Solution
- [   ] Implement Dynamic Programming Solution
