#include "stdio.h"

#define MAX_SCHEMES 20
#define MAX_APPLES 100

double min(double x, double y) {
    if ( x < y )
        return x;
    return y;
}

int main() {
    int desired_apples;
    double schemes[ MAX_SCHEMES ]; 
    double dp_table[ MAX_SCHEMES ][ MAX_APPLES ]; 
    for ( int i = 0; i < MAX_SCHEMES; i++ ) {
        schemes[i] = -1;
    }
    for ( int i = 0; i < MAX_SCHEMES; i++ ) {
        for ( int j = 0; j < MAX_APPLES; j++ ) {
            dp_table[i][j] = 100000000000;
        }
    }

    int given_scheme;
    int key; double value;
    double base_price;
    int total_schemes;
    scanf("%lf %d", &base_price, &total_schemes);
    schemes[1] = base_price;
    given_scheme = total_schemes;

    int highest_scheme_index = -1;
    int highest_value = -1;
    for ( int i = 0; i < given_scheme; i++ ) {
        scanf( "%d %lf", &key, &value );
        schemes[key] = value;
        if ( value > highest_value ) { 
            highest_scheme_index = key; 
            highest_value = value;
        }
    }
    scanf( "%d", &desired_apples );

    // Print scheme table
    printf("Schemes:\n");
    for ( int i = 1; i <= highest_scheme_index; i++ ) {
        if ( schemes[i] > 0 )
            printf("%d for $%.2lf, ", i, schemes[i]);
    }
    printf("\n");

    // If make sure to check all scheme even if desired apples are less than schemes
    int og_desired_apples = desired_apples;
    if ( desired_apples < highest_scheme_index ) { 
        desired_apples = highest_scheme_index; 
    }

    // Fill out basecase
    for ( int i = 0; i <= desired_apples; i++ ) {
        dp_table[1][i] = schemes[1] * i;
    }
    // Use dp to fill out the rest of the table
    for ( int i = 2; i <= highest_scheme_index; i++ ) {
        for ( int j = 0; j <= desired_apples; j++ ) {
            dp_table[i][j] = dp_table[ i - 1 ][j];
            if ( schemes[i] > 0 && j >= i )  
                dp_table[i][j] = min( dp_table[i][j], schemes[i] + dp_table[i][j-i] ); 
        }

        // Account for better deal with the same price but with more apples
        double prev_largest = dp_table[i][desired_apples];
        for ( int j = desired_apples; j > 0; j-- ) {
            if ( prev_largest < dp_table[i][j] ) {
                dp_table[i][j] = prev_largest;
            }
            prev_largest = dp_table[i][j];
        }
    }
    // Print DP Table
    printf("\n");
    printf("DP Table:\n");
    for ( int i = 1; i <= highest_scheme_index; i++ ) {
        printf("%d| ", i);
        for ( int j = 1; j <= desired_apples; j++ ) {
            printf("$%.2lf, ", dp_table[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Print out what to buy
    printf("Buy %d, at:\n", og_desired_apples );
    int i = highest_scheme_index;
    int j = desired_apples;
    while (1) {
        if ( dp_table[i][j] != dp_table[i-1][j] ) {
            printf("%d for $%.2lf\n", i, schemes[i]);
            i = i - 1;
            if ( i <= 0 ) break;
        }
        j = j - i;
        if ( j <= 0 ) break;
    }
    printf("For a total of: $%.2lf\n", dp_table[highest_scheme_index][desired_apples]);
    return 0;
}

