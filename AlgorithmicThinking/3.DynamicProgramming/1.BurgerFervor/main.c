#include <stdio.h>
#include <stdlib.h>

int solve( int burger_a, int burger_b, int time, int counter );
int max( int x, int y );
int * memo;
int main(int argc, char *argv[])
{
    int i;
    int a, b, t;
    scanf("%d %d %d", &a, &b, &t);
    memo = malloc( sizeof(int *) * t );
    for (i = 0; i < t; i++) {
        memo[i] = -2;
    }
    solve( a, b, t, -1);
    for ( i = 0; i < t; i++ ){
        if ( memo[i] != -2 ) {
            printf( "%d min drinking bear. ate %d burgers\n", i, memo[i] );
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

int solve( int burger_a, int burger_b, int time, int counter ) {

    if ( time == 0 ) {
        counter++;
        memo[time] = max( memo[time], counter );
        return counter;
    }
    counter++;

    int after_eating_a, after_eating_b;
    after_eating_a = after_eating_b = counter;

    if ( time >= burger_a ) {
        // Eating burger_a
        after_eating_a = solve( burger_a, burger_b, time - burger_a, counter );
    }

    if ( time >= burger_b ) {
        // Eating burger_b
        after_eating_b = solve( burger_a, burger_b, time - burger_b, counter );
    }

    int max_tmp = max( after_eating_a, after_eating_b );
    memo[time] = max( memo[time], max_tmp );

    return memo[time];
}

