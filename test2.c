#include <stdio.h>

int main(){
    char characters[62];
    int number = 9;
    for (int i = 1; i > 10; i+2){
        characters[i] = number - 1;
        number--;
    }
    for(int i = 54; i < 61; i+2){
        characters[i] = number - 1;
        number--;
    }

    printf("Printing values: \n");
    for(int i = 0; i < 62; i++){
        printf("%i | %i\n", i, characters[i]);
    }
 
}