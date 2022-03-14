#include <stdio.h>
#include <stdlib.h>

#define HASHMOD 1000

/* Type declarations */

typedef struct Snowflake {
    int legs[6];
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

    for ( i = 0; i < HASHMOD; i++ ) {
        hashTable[i] = NULL;
    }

    int numOfSnowflakes;
    scanf( "%d", &numOfSnowflakes );

    Snowflake snowflakes[100000];
    int hash;
    for ( i = 0; i < numOfSnowflakes; i++ ) {
        scanf( "%d %d %d %d %d %d", &snowflakes[i].legs[0], &snowflakes[i].legs[1], &snowflakes[i].legs[2], &snowflakes[i].legs[3], &snowflakes[i].legs[4], &snowflakes[i].legs[5] );
        hash = snowflakes[i].legs[0] + snowflakes[i].legs[1] + snowflakes[i].legs[2] + snowflakes[i].legs[3] + snowflakes[i].legs[4] + snowflakes[i].legs[5];
        
        hash = hash % HASHMOD;
        HashNode* hashNode = (HashNode*)malloc(sizeof(HashNode));
        hashNode->snowflake = snowflakes[i];
        hashNode->nextSnowflake = hashTable[hash];
        hashTable[hash] = hashNode;
    }

    int leftMatches, rightMatches;
    for (i = 0; i < HASHMOD; i++) {
        if (hashTable[i] != NULL){
            HashNode* currentNode = hashTable[i];
            while (currentNode != NULL && currentNode->nextSnowflake != NULL){
                HashNode* nextNode = currentNode->nextSnowflake;
                while (nextNode != NULL){
                    leftMatches = compareLeft( currentNode->snowflake.legs, nextNode->snowflake.legs);
                    rightMatches = compareRight( currentNode->snowflake.legs, nextNode->snowflake.legs);
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


int compareRight(int currentFlake[], int nextFlake[]) {
    int i;
    int currentLeg = 0;
    int matchLegs = 0;
    for ( i = 0; i < 6; i++ ) {
        if ( currentFlake[currentLeg] == nextFlake[i]) {
            matchLegs = 0;
            int k;
            for (k = 0; k < 6; k++ ) {
                int index = i + k;
                if ( index > 5 ) {
                    index -= 6;
                }

                if ( currentFlake[currentLeg + k % 6] == nextFlake[index] ) {
                    if (matchLegs == 6) {
                        return matchLegs;
                    }
                    matchLegs++;
                }
            }
        }
    }
    return matchLegs;
}

int compareLeft(int currentFlake[], int nextFlake[]) {
    int i;
    int currentLeg = 0;
    int matchLegs = 0;
    for ( i = 0; i < 6; i++ ) {
        if ( currentFlake[currentLeg] == nextFlake[i]) {
            matchLegs = 0;
            int k;
            for (k = 0; k < 6; k++ ) {
                int index = i - k;
                if ( index < 0 ) {
                    index += 6;
                }
                if ( currentFlake[currentLeg + k % 6] == nextFlake[index] ) {
                    if (matchLegs == 6) {
                        return matchLegs;
                    }
                    matchLegs++;
                }
            }
        }
    }
    return matchLegs;
}
