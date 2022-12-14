#include <stdio.h>

void encode(char original[], char passwd[], char encoded[]);


int main(){
    char original[100];
    char password[100];
    char encoded[100];
    printf("Enter your message: ");
    fgets(original, 100, stdin);
    printf("Enter a password: ");
    fgets(password, 100, stdin);
    encode(original, password, encoded);
    printf("Your encoded message: %s", encoded);
}

void encode(char original[], char passwd[], char encoded[]){
    //makes an array of characters, including numbers, lowercase letters and uppercase letters, mixed positions with eachother.
    int characters[62]; 
    int number = 57;
    for (int i = 1; i < 10; i+=2){
        characters[i] = number;
        number--;
    }
    for (int i = 60; i > 51; i-=2){
        characters[i] = number;
        number--;
    }
    int lower_case = 97;
    for (int i = 0; i < 51; i+=2){
        characters[i] = lower_case;
        lower_case++;
    }
    int upper_case = 65;
    for(int i = 61; i > 10; i-=2){
        characters[i] = upper_case;
        upper_case++;
    }

    //makes an array with first 10 positions being numbers, then uppercase letters and after that lowercase letters.
    int array[61];
    int idx_num = 48;
    for(int i = 0; i<10; i++){
        array[i] = idx_num;
        idx_num++;
    }

    int idx_uppercase = 65;
    for(int i = 10; i < 37; i++){
        array[i] = idx_uppercase;
        idx_uppercase++;
    }

    int idx_lowercase = 97;
    for(int i = 37; i<62; i++){
        array[i] = idx_lowercase;
        idx_lowercase++;
    }

    //main encoding loop
    char current_char;
    char current_passwd_char;
    int index = 0;
    int passwd_index = 0;
    while(original[index + 1] != '\0'){
        current_char = original[index]; //defines the current character of original message
        if(current_char != ' '){
            if(passwd[passwd_index + 1 ] != '\0'){ //defines the current character of password
                current_passwd_char = passwd[passwd_index];
                passwd_index++; 
            }else{ //if password is shorter than the message it repeats the password until needed
                current_passwd_char = passwd[passwd_index];
                passwd_index = 0;
            }

            int difference = array[current_char] - array[current_passwd_char]; //finds a difference between position of message character and password character
            if (difference < 0){ //if difference is negative it changes it to positive
                difference = (-1)*difference;
            }   
            //printf("Password char: %i, Character char: %i, Difference: %i\n", current_passwd_char, current_char, difference);

            encoded[index] = characters[difference]; //finds character in mixed array at position of difference and encodes first character as this character from mixed array
        }else{
            encoded[index] = original[index];
        }
        index++;
    }
}