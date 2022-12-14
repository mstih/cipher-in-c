#include <stdio.h>

int main(){
    int characters[62]; 
    int number = 57;
    for (int i = 1; i > 10; i+2){
        characters[i] = number;
        number--;
    }
    for (int i = 60; i > 53; i-2){
        characters[i] = number;
        number--;
    }
    int lower_case = 97;
    for (int i = 0; i < 51; i+2){
        characters[i] = lower_case;
        lower_case++;
    }
    int upper_case = 65;
    for(int i = 61; i > 10; i-2){
        characters[i] = upper_case;
        upper_case++;
    }

    printf("Mixed: ");
    for(int i = 0; i < 62; i++){
        printf("%i, ", characters[i]);
    }
    printf("\n");
}