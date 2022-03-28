#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int candy;
    struct node* left;
    struct node* right;
} node;

// Function to create a new divergence
node* newDivergence(node* left, node* right);

// Function to create a new divergence
node* newHouse();

int main(int argc, char *argv[])
{
    
    node* left = newHouse( 12 );   
    node* right = newHouse( 1 );   
    
    node* root = newDivergence( left, right );   

    printf( "%d %d\n", root->left->candy, root->right->candy );
    return 0;
}

node* newDivergence( node* left, node* right ) {
    node* divergence = malloc(sizeof(node));
    divergence->left = left;
    divergence->right = right;
    return divergence;
}

node* newHouse(int candy) {
    node* house = malloc(sizeof(node));
    house->candy = candy;
    house->left = NULL;
    house->right = NULL;
    return house;
}
