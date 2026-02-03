#include <stdio.h>
#include <string.h>

int getUserInput(int* choice1, int* choice2);
void printWordSquare(char* wordA, char* wordB);

int getUserInput(int* choice1, int* choice2){
    /*
     1. Prompt the user with this phrase: "Enter the number for the first word and hit enter:"
     2. Gather the user's input for a single integer via scanf(), saving this value into the choice1 parameter.
     3. Prompt the user with this phrase: "Enter the number for the second word and hit enter:"
     4. Gather the user's input for a single integer via scanf(), saving this value into the choice2 parameter.
     5. If either entered value is outside the range of 1 - 10, then return 1, otherwise return 0.
     */
    printf("Enter the number for the first word and hit enter: ");
    scanf("%d", choice1);
    printf("Enter the number for the second word and hit enter: ");
    scanf("%d", choice2);
    if((*choice1 < 1 || *choice1 > 10) || (*choice2 < 1 || *choice2 > 10)){
        return 1;
    } else{
        return 0;
    }

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
            printf("%s\n", wordA);
        }else{
            printf("%.*s",i, wordB);
            printf("%s\n", wordA+i);
        }
    }
}

int main(){
    char* word1 = "panda";
    char* word2 = "fox";
    char* word3 = "bear";
    char* word4 = "elephant";
    char* word5 = "rhinocerous";
    char* word6 = "giraffe";
    char* word7 = "ant";
    char* word8 = "badger";
    char* word9 = "centaur";
    char* word10 = "parakeet";
    printf("My words are: \n");
    printf("1: %s\n", word1);
    printf("2: %s\n", word2);
    printf("3: %s\n", word3);
    printf("4: %s\n", word4);
    printf("5: %s\n", word5);
    printf("6: %s\n", word6);
    printf("7: %s\n", word7);
    printf("8: %s\n", word8);
    printf("9: %s\n", word9);
    printf("10: %s\n", word10);

    char* wordA;
    char* wordB;
    int value1, value2;
    int value = getUserInput(&value1, &value2);
    if(value == 1){
        printf("ERROR: At least one word choice is out of bounds!");
    }else{
        switch(value1){
            case 1:
                wordA = word1;
                break;
            case 2:
                wordA = word2;
                break;
            case 3:
                wordA = word3;
                break;
            case 4:
                wordA = word4;
                break;
            case 5:
                wordA = word5;
                break;
            case 6:
                wordA = word6;
                break;
            case 7:
                wordA = word7;
                break;
            case 8:
                wordA = word8;
                break;
            case 9:
                wordA = word9;
                break;
            default:
                wordA = word10;
                break;
        }
        switch(value2){
            case 1:
                wordB = word1;
                break;
            case 2:
                wordB = word2;
                break;
            case 3:
                wordB = word3;
                break;
            case 4:
                wordB = word4;
                break;
            case 5:
                wordB = word5;
                break;
            case 6:
                wordB = word6;
                break;
            case 7:
                wordB = word7;
                break;
            case 8:
                wordB = word8;
                break;
            case 9:
                wordB = word9;
                break;
            default:
                wordB = word10;
                break;
        }
        printWordSquare(wordA, wordB);
    }
    return 0;
}

