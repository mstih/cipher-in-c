#include <stdio.h>

void encode(char original[], char passwd[]);


int main(){
    char original[100];
    char password[100];
    int characters[62];
    printf("Enter your message: ");
    fgets(original, sizeof(original), stdin);
    encode(original, password);
    printf("Your encoded message: %s", original);
}

void encode(char original[], char passwd[]){
    int characters[62]; //array with lowercase, upercase letters and numbers
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

    //main encoding loop
    char current_char;
    char current_passwd_char;
    int index = 0;
    while(original[index] != '\0'){
        current_char = original[index];



        int passwd_index = 0;
        while(passwd[passwd_index + 1 ] != '\0'){
            current_passwd_char = passwd[passwd_index];
            if(passwd[passwd_index + 1] != '\0'){
                passwd_index++;
            }else{
                passwd_index = 0;
            }
        }

        int difference = (int) current_char - (int) current_passwd_char;

    




    index++;
    }
}