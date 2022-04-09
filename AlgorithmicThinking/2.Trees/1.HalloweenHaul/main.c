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

node* createTree();

// Get the total candy of all node that are decendent of var root
int treeCandy( node* root );
int countLeaves( node* root );
int countStreets( node* root );
int getHeight( node* root );
node* read_tree( char* input );
node* read_tree_helper(char* input, int* pos );

// Input (((72 3) (6 (((4 9) 15) 2))) (7 41))
int main(int argc, char *argv[])
{
    /**
    node* g_left = newHouse( 7 );   
    node* g_right = newHouse( 41 );   
    node* g  = newDivergence( g_left, g_right );   

    node* b_left = newHouse( 4 );   
    node* b_right = newHouse( 9 );   
    node* b  = newDivergence( b_left, b_right );   

    node* c_right = newHouse( 15 );   
    node* c = newDivergence( b, c_right );

    node* d_right = newHouse( 2 );
    node* d = newDivergence( c, d_right );

    node* e_left = newHouse( 6 );
    node* e = newDivergence( e_left, d );

    node* a_left = newHouse( 72 );
    node* a_right = newHouse( 3 );
    node* a = newDivergence( a_left, a_right );

    node* f = newDivergence( a, e );

    node* root = newDivergence( f, g);   
     */

    node* root = read_tree( "(((72 3) (6 (((4 9) 15) 2))) (7 41))" );

    int totalCandy = treeCandy( root );
    printf("Total Candy: %d\n", totalCandy);

    int totalLeaves = countLeaves( root );
    printf("Total houses: %d\n", totalLeaves);

    int totalStreets = countStreets( root );
    printf("Total street walked if we go back to root a the end: %d\n", totalStreets);

    int height = getHeight( root );
    printf("Longest street: %d\n", height);


    return 0;
}

node* read_tree( char* input ) {
    int pos = 0;
    return read_tree_helper( input, &pos );
}

node* read_tree_helper(char* input, int* pos ) {
    node* tree = malloc( sizeof(node) );
    if ( tree == NULL ) {
        fprintf( stderr, "malloc error on tree\n" );
        exit(1);
    }
    if ( input[*pos] == '(' ) {
        (*pos)++;
        tree->left = read_tree_helper( input, pos );
        (*pos)++;
        tree->right = read_tree_helper( input, pos );
        (*pos)++;
        return tree;
    }
    else {
        tree->left = NULL;
        tree->right = NULL;
        tree->candy = input[*pos] - '0';
        (*pos)++;
        if (input[*pos] != ')' && input[*pos] != ' ' && input[*pos] != '\0' ) {
            tree->candy = tree->candy * 10 + input[*pos] - '0';
            (*pos)++;
        }
        return tree;
    }
}

// Assuming we can stop once we reach the last house, get the min street walk
int getHeight( node* root ) {
    // Base case: we reach a node with no left and right nodes  
    if ( root->left == NULL && root->right == NULL ) {
        return 0;
    }
    // Recursive case: we reach a node with a left or a right node
    int leftHeight = getHeight( root->left ) + 1;
    // in that case, we will visit the taller node.
    int rightHeight = getHeight( root->right ) + 1;
    if ( leftHeight > rightHeight )
        return leftHeight;
    return rightHeight;
}

int countLeaves( node* root ) {
    if ( root->left == NULL && root->right == NULL ) {
        return 1;
    }
    return countLeaves( root->left ) + countLeaves( root->right );
}

int countStreets( node* root ) {
    // Termination condition: 
    if ( root->left == NULL && root->right == NULL ) {
        return 0;
    }
    return 4 + countStreets( root->left ) + countStreets( root->right );
}

int treeCandy( node* root ) {
    // Base case: this is a house node just get the candy
    if ( root->left == NULL && root->right == NULL ) {
        return root->candy;
    }

    // Recursive case: this is a diverged node so the candy
    // here should only tell us how much candy can be collected
    // from the decendent subtrees.
    return treeCandy( root->left ) + treeCandy( root->right );
}

node* newDivergence( node* left, node* right ) {
    node* divergence = malloc(sizeof(node));
    if ( divergence == NULL ) {
        fprintf( stderr, "Could not allocate memory for 'node* divergence'." );
        exit(1);
    }
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
