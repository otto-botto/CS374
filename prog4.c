#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int getUserInput(char* word1, char* word2);
void printWordSquare(char* wordA, char* wordB);

int getUserInput(char* word1, char* word2){
    return 0;
}

void printWordSquare(char* wordA, char* wordB){
    unsigned long len1 = strlen(wordA);
    unsigned long len2 = strlen(wordB);
    int length = 1;
    if(len1 > len2){
        length += (int)len2;
    }else{
        length += (int)len1;

    }
    for(int i = 0; i < length; i++ ){
        if( i == 0) {
            printf(" %s\n ", wordA);
        }else{
            printf("%.*s",i, wordB);
            printf("%s\n ", wordA+i);
        }
    }
}

int main(){
    /*
     1. Prompt the user with this phrase: "Enter the first word and hit enter:"
     2. Gather the user's input for a single string via getline(), saving this value into the word1 parameter.
     3. Prompt the user with this phrase: "Enter the first word and hit enter:"
     4. Gather the user's input for a single string via getline(), saving this value into the word2 parameter.
     5. If either entered string has any uppercase letters, then the program should exit as shown.
    */

    char* wordA;
    char* wordB;
    ssize_t bufferSize = 33;
    int numCharsEntered1 = -5;
    int numCharsEntered2 = -5;

    wordA = calloc(bufferSize, sizeof(char));
    wordB = calloc(bufferSize, sizeof(char));

    printf("Enter the first word and hit enter: ");
    numCharsEntered1 = getline(&wordA, &bufferSize, stdin);

    printf("Enter the second word and hit enter: ");
    numCharsEntered2 = getline(&wordB, &bufferSize, stdin);

    if (numCharsEntered1 > 33 || numCharsEntered2 > 33) {
        if (numCharsEntered1 > 33) {
            numCharsEntered1 = 33;
        } else if (numCharsEntered2 > 33) {
            numCharsEntered2 = 33;
        }
    }

    // clean up the words from \n
    char* wordAClean = calloc(numCharsEntered1, sizeof(char));
    char* wordBClean = calloc(numCharsEntered2, sizeof(char));
    snprintf(wordAClean, numCharsEntered1, "%s", wordA);
    snprintf(wordBClean, numCharsEntered2, "%s", wordB);

    printf("NORMAL\n");

    printWordSquare(wordAClean, wordBClean);

    printf("INVERTED\n");

    free(wordA);
    free(wordB);

    return 0;
}

