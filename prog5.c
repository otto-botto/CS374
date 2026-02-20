#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define STR_LEN 33

typedef struct{
    int type; // 0 for long, 1 for double, and 2 for string
    long int longValue;
    double doubleValue;
    char stringValue[33];
}Level;

void push(Level* arrayStack, Level new, int* top) {
    if (*top != 4) {
        (*top)++;
        arrayStack[*top] = new;
    }else {
        arrayStack[*top] = new;
    }
}

void pop(int* top) {
    if ((*top)!= -1) {
        (*top)--;
    }
}


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
    int top = -1;
    Level myArrayStack[5];

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
            case 0: {
                // don't need to capture endptr like in check_input, because validated long, pass NULL
                Level newLevel = {result, strtol(input, NULL,10), 0.0, ""};
                push(myArrayStack, newLevel, &top);
                break;
            }
            case 1: {
                // don't need to capture endptr like in check_input, because validated double, pass NULL
                Level newLevel = {result, 0, strtod(input, NULL), ""};
                push(myArrayStack, newLevel, &top);
                break;
            }
            case 2:{
                if(numCharsEntered <= STR_LEN){
                    Level newLevel = {result, 0, 0.0, ""};
                    strcpy(newLevel.stringValue, input);
                    push(myArrayStack, newLevel, &top);
                    break;
                } // longer, go to the default}
            default: {
                    printf("Invalid input.\n");
                    break;
                }
        }
    }
    free(input);
    return 0;
}

