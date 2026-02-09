#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define BUFFER 34

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
    // allocate memory for each row of the normal matrix
    char** normal = calloc(length, sizeof(char*));
    for(int i = 0; i < length; i++ ){
        // allocate memory to hold an entire string, up to space + 32 + '\0' == 34
        normal[i] = calloc(BUFFER, sizeof(char));
        snprintf(normal[i],BUFFER, " %.*s%s",i, wordB, wordA+i);
    }

    for (int i = 0; i < length; i++) {
        for (int j = 0; j < strlen(wordA)+1; j++) {
            printf("%c", normal[i][j]);
        }
        putchar('\n');
    }
}

int main(){
    /*
     1. Prompt the user with this phrase: "Enter the first word and hit enter:"
     2. Gather the user's input for a single string via getline(), saving this value into the wordA parameter.
     3. Prompt the user with this phrase: "Enter the first word and hit enter:"
     4. Gather the user's input for a single string via getline(), saving this value into the wordB parameter.
     5. If either entered string has any uppercase letters, the program exits with "Invalid character, exiting".
    */

    char* wordA;
    char* wordB;
    ssize_t bufferSize = 33;
    int numCharsEntered1 = -5;
    int numCharsEntered2 = -5;

    wordA = calloc(bufferSize, sizeof(char));
    wordB = calloc(bufferSize, sizeof(char));

    while (1) {
        printf("Enter the first word and hit enter: ");
        numCharsEntered1 = getline(&wordA, &bufferSize, stdin);
        // check for invalid characters
        for (int i = 0; i < numCharsEntered1; i++) {
            char letter = wordA[i];
            if ((!isalpha(letter) || isupper(letter)) && letter != '\n') {
                printf("Invalid character, exiting.\n");
                free(wordA);
                return 0;
                // exit(EXIT_SUCCESS);
            }
        }

        printf("Enter the second word and hit enter: ");
        numCharsEntered2 = getline(&wordB, &bufferSize, stdin);
        // check for invalid characters
        for (int i = 0; i < numCharsEntered2; i++) {
            char letter = wordB[i];
            if ((!isalpha(letter) || isupper(letter)) && letter != '\n') {
                printf("Invalid character, exiting.\n");
                free(wordB);
                return 0;
                // exit(EXIT_SUCCESS);
            }
        }


        if (numCharsEntered1 > 33 || numCharsEntered2 > 33) {
            if (numCharsEntered1 > 33) {
                numCharsEntered1 = 33;
            } else if (numCharsEntered2 > 33) {
                numCharsEntered2 = 33;
            }
        }

        // clean up the words from \n
        /*
         * allocate memory for both word A and B
         * copy, but only up to 32 chars from A and B into new strings
         */
        char* wordAClean = calloc(numCharsEntered1, sizeof(char));
        char* wordBClean = calloc(numCharsEntered2, sizeof(char));
        snprintf(wordAClean, numCharsEntered1, "%s", wordA);
        snprintf(wordBClean, numCharsEntered2, "%s", wordB);

        printf("NORMAL\n");

        printWordSquare(wordAClean, wordBClean);

        printf("INVERTED\n");

        free(wordAClean);
        free(wordBClean);
    }
}

