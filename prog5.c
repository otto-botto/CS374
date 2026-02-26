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

int pop(int* top) {
    if ((*top)!= -1) {
        (*top)--;
        return 0;
    }else {
        return 1;
    }
}

void roll(Level* arrayStack, int top) {
    for (int i = 0; i < top; i++) {
        Level tmp = arrayStack[i];
        arrayStack[i] = arrayStack[i+1];
        arrayStack[i+1] = tmp;
    }
}

int add(Level* arrayStack, int* top){
    if (*top <= 0) {
        return 1;
    }else {
        Level newLevel = {0,0,0.0,""};
        if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 0){
            long int newLongValue= arrayStack[(*top)-1].longValue + arrayStack[*top].longValue;
            newLevel.longValue = newLongValue;
        }else if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].longValue + arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 0){
            double newDoubleValue= arrayStack[(*top)-1].doubleValue + arrayStack[*top].longValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].doubleValue + arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 2 && arrayStack[*top].type == 2){
            char newStringValue[64] = {0};
            sprintf(newStringValue, "%s%s",arrayStack[(*top)-1].stringValue, arrayStack[*top].stringValue) ;
            strncpy(newLevel.stringValue, newStringValue, STR_LEN - 1);
            newLevel.stringValue[STR_LEN-1] = '\0'; // index 32 is \0
            newLevel.type = 2;
        }else if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 2){
            char newStringValue[64] = {0};
            sprintf(newStringValue, "%ld%s",arrayStack[(*top)-1].longValue, arrayStack[*top].stringValue) ;
            strncpy(newLevel.stringValue, newStringValue, STR_LEN - 1);
            newLevel.stringValue[STR_LEN-1] = '\0'; // index 32 is \0
            newLevel.type = 2;
        }else if (arrayStack[(*top)-1].type == 2 && arrayStack[*top].type == 0){
            char newStringValue[64] = {0};
            sprintf(newStringValue, "%s%ld",arrayStack[(*top)-1].stringValue, arrayStack[*top].longValue) ;
            strncpy(newLevel.stringValue, newStringValue, STR_LEN - 1);
            newLevel.stringValue[STR_LEN-1] = '\0'; // index 32 is \0
            newLevel.type = 2;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 2){
            char newStringValue[64] = {0};
            sprintf(newStringValue, "%f%s",arrayStack[(*top)-1].doubleValue, arrayStack[*top].stringValue) ;
            strncpy(newLevel.stringValue, newStringValue, STR_LEN - 1);
            newLevel.stringValue[STR_LEN-1] = '\0'; // index 32 is \0
            newLevel.type = 2;
        }else if (arrayStack[(*top)-1].type == 2 && arrayStack[*top].type == 1){
            char newStringValue[128] = {0};
            sprintf(newStringValue, "%s%f",arrayStack[(*top)-1].stringValue, arrayStack[*top].doubleValue) ;
            strncpy(newLevel.stringValue, newStringValue, STR_LEN - 1);
            newLevel.stringValue[STR_LEN-1] = '\0'; // index 32 is \0
            newLevel.type = 2;
        }
        pop(top);
        pop(top);
        push(arrayStack, newLevel, top);
        return 0;
    }
}

int subtract(Level* arrayStack, int* top){
    if (*top <= 0) {
        return 1;
    }else {
        Level newLevel = {0,0,0.0,""};
        if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 0){
            long int newLongValue= arrayStack[(*top)-1].longValue - arrayStack[*top].longValue;
            newLevel.longValue = newLongValue;
        }else if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].longValue - arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 0){
            double newDoubleValue= arrayStack[(*top)-1].doubleValue - arrayStack[*top].longValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].doubleValue - arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 2 || arrayStack[*top].type == 2){
            return 2;
        }
        pop(top);
        pop(top);
        push(arrayStack, newLevel, top);
        return 0;
    }
}

int multiply(Level* arrayStack, int* top){
    if (*top <= 0) {
        return 1;
    }else {
        Level newLevel = {0,0,0.0,""};
        if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 0){
            long int newLongValue= arrayStack[(*top)-1].longValue * arrayStack[*top].longValue;
            newLevel.longValue = newLongValue;
        }else if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].longValue * arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 0){
            double newDoubleValue= arrayStack[(*top)-1].doubleValue * arrayStack[*top].longValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].doubleValue * arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 2 || arrayStack[*top].type == 2){
            return 2;
        }
        pop(top);
        pop(top);
        push(arrayStack, newLevel, top);
        return 0;
    }
}

int divide(Level* arrayStack, int* top){
    if (*top <= 0) {
        return 1;
    }else if ((arrayStack[*top].type == 0 && arrayStack[*top].longValue == 0) ||
        (arrayStack[*top].type == 1 && arrayStack[*top].doubleValue == 0.0) ) {
        return 2;
    }else {
        Level newLevel = {0,0,0.0,""};
        if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 0){
            long int newLongValue= arrayStack[(*top)-1].longValue / arrayStack[*top].longValue;
            newLevel.longValue = newLongValue;
        }else if (arrayStack[(*top)-1].type == 0 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].longValue / arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 0){
            double newDoubleValue= arrayStack[(*top)-1].doubleValue / arrayStack[*top].longValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 1 && arrayStack[*top].type == 1) {
            double newDoubleValue= arrayStack[(*top)-1].doubleValue / arrayStack[*top].doubleValue;
            newLevel.doubleValue = newDoubleValue;
            newLevel.type = 1;
        }else if (arrayStack[(*top)-1].type == 2 || arrayStack[*top].type == 2){
            return 3;
        }
        pop(top);
        pop(top);
        push(arrayStack, newLevel, top);
        return 0;
    }
}

void print_stack(Level* arrayStack, int top) {
    if (top < 0) {
        printf("Empty Stack\n");
    }
    for (int i = 0; i <= top; i++) {
        switch (arrayStack[i].type) {
            case 0: {
                printf("%d: %ld\n", top+1 - i, arrayStack[i].longValue);
                break;
            }
            case 1: {
                printf("%d: %f\n", top+1 - i, arrayStack[i].doubleValue);
                break;
            }
            case 2: {
                printf("%d: %s\n", top+1 - i, arrayStack[i].stringValue);
                break;
            }
        }
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

void logging(FILE* fileStream, char* input, Level* arrayStack, int top, int mathResult) {
    if (strlen(input) != 0) {
        fprintf(fileStream, "%s\n", input);
    }
    if (top < 0 && mathResult != 4) {
        fprintf(fileStream,"Empty Stack\n");
    }

    if (mathResult != 0) {
        switch (mathResult) {

            case
                printf("Insufficient Arguments\n");
                fprintf(fileStream, "Insufficient Arguments\n");
            }
            case 2: {
                printf("Bad Arguments\n");
                fprintf(fileStream, "Bad Arguments\n");
            }
            case 3: {
                printf("Division by Zero\n");
                fprintf(fileStream, "Division by Zero\n");
            }
            case 4: {
                printf("Bad Input\n");
                fprintf(fileStream, "Bad Input\n");
            }


        }
    }
    for (int i = 0; i <= top; i++) {
        switch (arrayStack[i].type) {
            case 0: {
                printf("%d: %ld\n", top+1 - i, arrayStack[i].longValue);
                fprintf(fileStream,"%d: %ld\n", top+1 - i, arrayStack[i].longValue);
                break;
            }
            case 1: {
                printf("%d: %f\n", top+1 - i, arrayStack[i].doubleValue);
                fprintf(fileStream,"%d: %f\n", top+1 - i, arrayStack[i].doubleValue);
                break;
            }
            case 2: {
                printf("%d: %s\n", top+1 - i, arrayStack[i].stringValue);
                fprintf(fileStream,"%d: %s\n", top+1 - i, arrayStack[i].stringValue);
                break;
            }
        }
    }

}


int main() {
    char *input;
    size_t bufferSize = STR_LEN;
    int numCharsEntered = -5;

    input = calloc(bufferSize, sizeof(char));
    int top = -1;
    Level myArrayStack[5];

    // open a file stream to log into
    FILE* fileStream = NULL;
    char* filePath = "prog5_log.txt";
    fileStream = fopen(filePath, "w");

    int math_result = -1;

    while (1) {
        // prompt

        // print_stack(myArrayStack, top);
        logging(fileStream, input, myArrayStack, top, math_result);
        if (top < 0) printf("Empty Stack\n");
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



        // check for commands
        if (strcmp(input, "d") == 0) {
            math_result = pop(&top);
            logging(fileStream, input, myArrayStack, top, math_result);
        } else if (strcmp(input, "q") == 0) {
            fprintf(fileStream, "q\n");
            break;
        }else if (strcmp(input, "r") == 0) {
            roll(myArrayStack, top); //TODO: finish this command
        }else if (strcmp(input, "+") == 0) {
            math_result = add(myArrayStack, &top);
            logging(fileStream, input, myArrayStack, top, math_result);
        }else if (strcmp(input, "-") == 0) {
            math_result = subtract(myArrayStack, &top);
            logging(fileStream, input, myArrayStack, top, math_result);
        }else if (strcmp(input, "*") == 0) {
            math_result = multiply(myArrayStack, &top);
            logging(fileStream, input, myArrayStack, top, math_result);
        } else if (strcmp(input, "/") == 0) {
            math_result = divide(myArrayStack, &top);
            logging(fileStream, input, myArrayStack, top, math_result);
        } else {
            // check if the entry is valid
            int result = check_input(input, numCharsEntered);
            switch(result){
                case 0: {
                    // don't need to capture endptr like in check_input, because validated long, pass NULL
                    Level newLevel = {result, strtol(input, NULL,10), 0.0, ""};
                    push(myArrayStack, newLevel, &top);
                    math_result = 0;
                    break;
                }
                case 1: {
                    // don't need to capture endptr like in check_input, because validated double, pass NULL
                    Level newLevel = {result, 0, strtod(input, NULL), ""};
                    push(myArrayStack, newLevel, &top);
                    math_result = 0;
                    break;
                }
                case 2:{
                    if(numCharsEntered <= STR_LEN){
                        Level newLevel = {result, 0, 0.0, ""};
                        strcpy(newLevel.stringValue, input);
                        push(myArrayStack, newLevel, &top);
                        math_result = 0;
                        break;
                    } // longer, go to the default
                    default: {
                        math_result = 4;
                        break;
                    }
                }
            }
        }
    }
    free(input);
    fclose(fileStream);
    return 0;
}


