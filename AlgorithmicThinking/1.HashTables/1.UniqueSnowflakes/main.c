#include <stdio.h>
#include <stdlib.h>

/******************************************************************************
* File:             main.c
*
* Author:           Khanh Vong  
* Created:          03/14/22 
* Description:      Practice implementing a hashtable to quickly find similar 
*                   snowflakes
*****************************************************************************/


// Set the size of the hash table
#define HASHMOD 1000

/* Type declarations */
typedef struct Snowflake {
    int arms[6];
    int groupId;
} Snowflake;

typedef struct HashNode {
    Snowflake snowflake;
    struct HashNode *nextSnowflake;
} HashNode;

/* Function declarations */
int compareRight(int currentFlake[], int nextFlake[]);
int compareLeft(int CurrentFlake[], int nextFlake[]);
int cleanHashTable(HashNode* hashTable[HASHMOD]);

int main(int argc, char *argv[])
{
    int i;
    HashNode* hashTable[HASHMOD];

    // Set everything in the hashtable to NULL
    for ( i = 0; i < HASHMOD; i++ ) {
        hashTable[i] = NULL;
    }

    int numOfSnowflakes;
    scanf( "%d", &numOfSnowflakes );

    Snowflake snowflakes[100000];
    int hash;
    for ( i = 0; i < numOfSnowflakes; i++ ) {
        // Read  snowflakes from stdin
        scanf( "%d %d %d %d %d %d", &snowflakes[i].arms[0], &snowflakes[i].arms[1], &snowflakes[i].arms[2], &snowflakes[i].arms[3], &snowflakes[i].arms[4], &snowflakes[i].arms[5] );

        // Make the hash the sum of the snowflake's arms
        hash = snowflakes[i].arms[0] + snowflakes[i].arms[1] + snowflakes[i].arms[2] + snowflakes[i].arms[3] + snowflakes[i].arms[4] + snowflakes[i].arms[5];
        
        // Bound the hash with HASHMOD defined on line 1
        hash = hash % HASHMOD;

        // Add the snowflake as a linked list to the hash table index
        HashNode* hashNode = (HashNode*)malloc(sizeof(HashNode));
        hashNode->snowflake = snowflakes[i];
        hashNode->nextSnowflake = hashTable[hash];
        hashTable[hash] = hashNode;
    }

    int leftMatches, rightMatches;

    // Go through every entry of the hash table
    for (i = 0; i < HASHMOD; i++) {
        if (hashTable[i] != NULL){
            HashNode* currentNode = hashTable[i];
            
            // Traverse the linked list only if there's a comparison in the list
            while (currentNode != NULL && currentNode->nextSnowflake != NULL){
                HashNode* nextNode = currentNode->nextSnowflake;

                // Traverse next node
                while (nextNode != NULL){
                    leftMatches = compareLeft( currentNode->snowflake.arms, nextNode->snowflake.arms);
                    rightMatches = compareRight( currentNode->snowflake.arms, nextNode->snowflake.arms);
                    // Check if there was a match during the left or right comparison
                    if ( leftMatches == 6 || rightMatches == 6 ) {
                        printf("Twin snowflakes found.\n");
                        cleanHashTable(hashTable);
                        return 0;
                    } 
                    nextNode = nextNode->nextSnowflake;
                }
                currentNode = currentNode->nextSnowflake;
            }
        }
    }
    
    printf("No two snowflakes are alike.\n");
    
    cleanHashTable(hashTable);
    return 0;
}

/* Deallocate all allocated memory from hashtable */
int cleanHashTable(HashNode* hashTable[HASHMOD]) {
    int i;
    for (i = 0; i < HASHMOD; i++) {
        if (hashTable[i] != NULL) {
            HashNode* currentNode = hashTable[i];
            while (currentNode != NULL){
                HashNode* nextNode = currentNode->nextSnowflake;
                free(currentNode);
                currentNode = nextNode;
            }
        }
    }
}


/* Compare the arms of a snowflake form left to right */
int compareRight(int currentFlake[], int nextFlake[]) {
    int i;
    int currentArm = 0;
    int matchArms = 0;

    // Go through all sides of the nextFlake
    for ( i = 0; i < 6; i++ ) {

        // Find snowflake arm that match with the currentFlake curent arm
        // current flake's current arm must be in the nextFlake
        if ( currentFlake[currentArm] == nextFlake[i]) {
            matchArms = 0;
            int k;

            // Now that we have found a common arm,
            // from current arm position going to the right,
            // check if the next arm is similar to currentFlake's next arm.
            for (k = 0; k < 6; k++ ) {
                int index = (i + k) % 6; // Use modulus to cycle right: after 6 is 0

                if ( currentFlake[currentArm + k % 6] == nextFlake[index] ) {
                    if (matchArms == 6) {
                        return matchArms;
                    }
                    matchArms++;
                }
            }
        }
    }
    return matchArms;
}

/* Compare the arms of a snowflake form right to left */
int compareLeft(int currentFlake[], int nextFlake[]) {
    int i;
    int currentArm = 0;
    int matchArms = 0;

    // Go through all sides of the nextFlake and compare witht the currentFlake's current arm
    for ( i = 0; i < 6; i++ ) {
        
        // After finding the matching arm start comparing the remaining arms
        if ( currentFlake[currentArm] == nextFlake[i]) {
            matchArms = 0;
            int k;

            for (k = 0; k < 6; k++ ) {
                int index = (i - k + 6) % 6; // Use modulus to cycle left: after 0 is 6
                if ( currentFlake[currentArm + k % 6] == nextFlake[index] ) {
                    if (matchArms == 6) {
                        return matchArms;
                    }
                    matchArms++;
                }
            }
        }
    }
    return matchArms;
}
