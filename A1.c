#include <stdio.h>
#include <ctype.h>

int checkAnagram(char ana1[], char ana2[]){

    for (int position1 = 0; position1 < sizeof(ana1)/ sizeof(ana1[0]); position1++){
        if (ana1[position1] == "\0"){
                continue;
            }

        for (int position2 = 0; position2 < sizeof(ana2)/ sizeof(ana2[0]); position2++){
            if (ana2[position2] == "\0"){
                continue;
            }
            if (ana1[position1] == ana2[position2]){
                ana1[position1] = "\0";
                ana2[position2] = "\0";
                break;
            } 


        }

    }
    
    for (int i = 0; i < sizeof(ana1)/ sizeof(ana1[0]); i++){

        if (ana1[i] != ana2[i]){
            return -1;
        }
    }
    return 1;




}

int main(int argsc, char argv[]){
    FILE *anagram;
    char buffer[4096];
    char buffer2[4096];
    anagram = fopen(argv[1], "r");
    fget(buffer, sizeof(buffer), anagram);
    fget(buffer2, sizeof(buffer2), anagram);

    if (checkAnagram(buffer, buffer2) > 0){
        //Code for success
    } else {
        //Code for not anagram
    }






}



