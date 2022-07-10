#include <stdio.h>
#include <stdlib.h>

int solve_r( int burger_a, int burger_b, int time, int counter );
int solve_t_r( int, int, int );
int solve_t_m( int, int, int, int[]);
int solve_t_d( int, int, int );
void solve( int, int, int );
int max( int x, int y );
int * time_table;
int main(int argc, char *argv[])
{
    int i;
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    solve( a, b, t );
    time_table = malloc( sizeof(int *) * t );
    for (i = 0; i < t; i++) {
        time_table[i] = -2;
    }
    solve_r( a, b, t, -1);
    for ( i = 0; i < t; i++ ){
        if ( time_table[i] != -2 ) {
            printf( "%d min drinking bear. ate %d burgers\n", i, time_table[i] );
            break;
        }
    }

    return 0;
}

int max( int x, int y ) {
    if ( x > y )
        return x;
    return y;
}

// Solve using recursion + hash table overwriting [ My solution ]
int solve_r( int burger_a, int burger_b, int time, int counter ) {
    // Case where it's a perfect fit
    if ( time == 0 ) {
        counter++; // Eating the last burger

        // Check if we're able to eat more burgers
        // with this strategy than our previous one
        time_table[time] = max( time_table[time], counter ); 
        return counter;
    }

    counter++; // Eating the burger

    int after_eating_a, after_eating_b;
    after_eating_a = after_eating_b = counter;

    if ( time >= burger_a ) { // Can we eat burger_a? 
        // Eating burger_a
        after_eating_a = solve_r( burger_a, burger_b, time - burger_a, counter );
    }

    if ( time >= burger_b ) { // Can we eat burger_b?
        // Eating burger_b
        after_eating_b = solve_r( burger_a, burger_b, time - burger_b, counter );
    }

    // Get the burger that fits the better strategy
    int max_tmp = max( after_eating_a, after_eating_b );

    // Save result if the results are better than
    // what we currently have (more burgers than before?).
    time_table[time] = max( time_table[time], max_tmp );

    return time_table[time];
}

// Recursive Solution [Book Solution]
int solve_t_r( int m, int n, int t ) {
    int first, second;
    if ( t == 0 ) {
        return 0;
    }
    if ( t >= m ) 
        first = solve_t_r( m, n, t - m );
    else
        first = -1;

    if ( t >= n ) 
        second = solve_t_r( m, n, t - n );
    else
        second = -1;

    if ( first == -1 && second == -1 )
        return -1;
    else
        return max( first, second ) + 1;
}

int solve_t_m( int m, int n, int t, int memo[] ) {
    int first, second;
    if ( memo[t] != -2 )
        return memo[t];
    if ( t == 0 ) {
        memo[t] = 0;
        return memo[t];
    }
    if ( t >= m ) 
        first = solve_t_m( m, n, t - m, memo);
    else
        first = -1;

    if ( t >= n ) 
        second = solve_t_m( m, n, t - n, memo);
    else
        second = -1;

    if ( first == -1 && second == -1 ) {
        memo[t] = -1;
    }
    else {
        memo[t] = max( first, second ) + 1;
    }
    return memo[t];
}

void solve( int m, int n, int t ) {
    int memo[t+1];
    int result, i;
    for (i = 0; i <= t; i++) {
        memo[i] = -2;
    }
    // result = solve_t_r( m, n, t );
    result = solve_t_m( m, n, t, memo);
    if ( result >= 0 ) {
        printf( "%d burgers eaten\n", result );
    }
    else {
        i = t - 1;
        // result = solve_t_r( m, n, i );
        result = solve_t_m( m, n, i, memo);
        while ( result == -1 ) {
            i--;
            // result = solve_t_r( m, n, i );
            result = solve_t_m( m, n, i, memo);
        }
        printf( "%d burgers eaten, %d min drinking\n", result, t - i );
    }
}
