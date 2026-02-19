#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 33


int check_input(char* input, int length){
    // check if valid long integer, all numbers and no '.'
    char* endptr; // ptr to first char that can't be converted
    strtol(input, &endptr, 10);
    if (*endptr == '\0') {
        return 0;
    }

    // check if valid double, all numbers and one '.'
    strtod(input, &endptr);
    if (*endptr == '\0') {
        return 1;
    }

    // check if valid string, all lower case letters, spaces and <= 32 chars
    const char* allowed = "abcdefghijklmnopqrstuvwxyz0123456789 \t";
    if (strspn(input, allowed) == length) {
        return 2;
    }

    // invalid, return -1
    return -1;
}


int main() {
    char *input;
    size_t bufferSize = STR_LEN;
    int numCharsEntered = -5;


    input = calloc(bufferSize, sizeof(char));


    while (1) {
        // prompt
        printf("# ");
        numCharsEntered = getline(&input, &bufferSize, stdin);
        if(numCharsEntered == -1){
            break;
        }


        // remove the '\n' from getline()
        //    -- find the last char at input[length - 1] and replace it with \0
        if (input[numCharsEntered - 1] == '\n') {
            input[numCharsEntered - 1] = 0;
            numCharsEntered--;
        }
        // check if entry is valid
        int result = check_input(input, numCharsEntered);
        switch(result){
            case 0:
                printf("Valid long.\n");
                break;
            case 1:
                printf("Valid double.\n");
                break;
            case 2:
                if(numCharsEntered <= STR_LEN){
                    printf("Valid string.\n");
                    break;
                } // longer, go to the default
            default:
                printf("Invalid input.\n");
                break;
        }
    }
}

