# Problem #2: Moneygrubbers

## The Problem:
You want to buy apples, so you go to an apple store. The store has a price for bying one apple - for example, $1.75. The store also has *m* pricing schemes, where each pricing scheme gives a number *n* and a price *p* for buying *n* apples. For example, one pricing scheme might state that three apples cost a total of $4.00; another might state that two apples cost a total of $2.50. You want to buy *at least* *k* apples and do so as cheaply as possible.

### Input
- A line containing the price for buying one apple, followed by the number *m* of pricing schemes for the test case. *m* is at most 20. 
- *m* lines, each which gives a number *n* and total price *p* for buying *n* apples. *n* is between 1 and 100.
- A line containing the desired number of apples to buy.

### Output
Tell the user which scheme to use and how much they'll need to spend.

## The Solution
Build a table using dynamic programming 'bottom-up' approach. We start by filling out the first row; which is the base case of buying apples without any schemes applied. From the base case, we move to the next row, if the row doesnt have a scheme then we will use the value of the previous row. If the row does have a scheme, we'll use a scheme of the previous row up until where we can use the scheme.

| 1 for $1.75 | 2 for $2.00 | 4 for $3.00 |

|DP Table| 1 | 2 | 3 | 4 |
|----|----|----|----|----|
|1| $1.75| $3.50| $5.25| $7.00|
|2| $1.75| $2.00| $3.75| $4.00|
|3| $1.75| $2.00| $3.75| $4.00|
|4| $1.75| $2.00| $3.00| $3.00|

In the example above, see that we filled out the base case by multiplying the price per apple by the desired amount. For row 2, we took the value from the base case and applied it to the first index. Next, 2 is a scheme so we use the scheme which is cheaper than the value of the previous row. At the 3 index of the second row, we summed up the price of the scheme and the best price we can do after the scheme is applied. In this case, we want to buy 3 and we have a scheme of 2 for $2.00. After it's been applied use we only need to buy 1 which we already have the price from the previous row. 

In cases where there isn't a scheme, we'll simply use the values of the previous row. See this in row 3. There are better ways to do this by using a hashmap but just to keep it simple we'll just use the values from the previous row.

This problem asks for *atleast k* apples. What does that mean? It means if we can buy the desired amount of apples that would be great but there's nothing stopping us from buying more. See row 4.

Row 4 take into account the 4 for $3.00 scheme. Originally because row 3 did not have a scheme we had to use, the price from the previous row. With scheme 4, we see that we can buy an extra apple for a lower price and just buying with the previous schemes (free apple). Thus after we finish filing out a row, we'll to another pass to ensure that we are selecting the cheapest scheme.

### Dynamic Progamming Code
```
    for ( int i = 0; i <= desired_apples; i++ ) {
        dp_table[1][i] = schemes[1] * i;
    }
    for ( int i = 2; i <= highest_scheme_index; i++ ) {
        for ( int j = 0; j <= desired_apples; j++ ) {
            dp_table[i][j] = dp_table[ i - 1 ][j];
            if ( schemes[i] > 0 && j >= i )  
                dp_table[i][j] = min( dp_table[i][j], schemes[i] + dp_table[i][j-i] ); 
        }
        double prev_largest = dp_table[i][desired_apples];
        for ( int j = desired_apples; j > 0; j-- ) {
            if ( prev_largest < dp_table[i][j] ) {
                dp_table[i][j] = prev_largest;
            }
            prev_largest = dp_table[i][j];
        }
    }
```
