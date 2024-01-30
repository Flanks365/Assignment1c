#include <stdio.h>
#include <ctype.h>

int checkAnagram(char ana1[], char ana2[], FILE *out){
    char letters1[35];
    for (int i = 0; i < sizeof(letters1); i ++){
        letters1[i] = '0';
    }
    char letters2[35];
    for (int i = 0; i < sizeof(letters2); i ++){
        letters2[i] = '0';
    }


    for (int i = 0, j = 0; i < sizeof(letters1); i++){

        if (ana1[i] >= 'a' && ana1[i] <= 'z') {
            letters1[j] = ana1[i];
            j++;

        } 

        else if (ana1[i] >= 'A' && ana1[i] <= 'Z') {
            letters1[j] = (ana1[i] + 32);
            j++;

        } else if (ana1[i] == ' '){
            continue;
        } else if (ana1[i] == '\0'){
            break;
        }
        

    }

    for (int i = 0, j = 0; i < sizeof(letters2); i++){

        if (ana2[i] >= 'a' && ana2[i] <= 'z') {
            letters2[j] = ana2[i];
            j++;

        }

        else if (ana2[i] >= 'A' && ana2[i] <= 'Z') {
            letters2[j] = (ana2[i] + 32);
            j++;

        } else if (ana2[i] == ' '){
            continue;
        } else if (ana2[i] == '\0'){
            break;
        }
        

    }

    printf("\nLetters 1\n");


    for (int x = 0; x < sizeof(letters1); x++){
        printf("%c", letters1[x]);
    }
    printf("\nLetters 2\n");

    for (int x = 0; x < sizeof(letters2); x++){
        printf("%c", letters2[x]);
    }
    printf("\n");

    for (int position1 = 0; position1 < sizeof(letters1); position1++){
        for (int position2 = 0; position2 < sizeof(letters2); position2++){

        if (letters1[position1] == letters2[position2]){
                letters1[position1] = ' ';
                letters2[position2] = ' ';
                break;
            }
        }
    }
    printf("\nLetters 1\n");

    for (int x = 0; x < sizeof(letters1); x++){
        printf("%c", letters1[x]);
    }
    printf("\nLetters 2\n");

    for (int x = 0; x < sizeof(letters2); x++){
        printf("%c", letters2[x]);
    }
    printf("\n");

    for (int i = 0; i < sizeof(letters1); i++){

        if ((letters1[i] >= 'a' && letters1[i] <= 'z' ) || (letters2[i] >= 'a' && letters2[i] <= 'z' )){
            
            fputs("0! not anagram", out);
            return -1;
        }   
        
    }
    fputs("1! anagram", out);
    return 1;
    
}

int main(int argsc, char *argv[]){
    FILE *anagram;
    FILE *output;
    char buffer[1000];
    char buffer2[1000];
    anagram = fopen(argv[1], "r");
    output = fopen(argv[2], "w");
    fgets(buffer, sizeof(buffer), anagram);
    fgets(buffer2, sizeof(buffer2), anagram);
    

    if (checkAnagram(buffer, buffer2, output) > 0){
        printf("success\n");
    } else {
        printf("failure\n");
    }
}



