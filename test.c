#include <stdio.h>
#include <string.h>

void encode(char original[], char passwd[], char encoded[]);

int main()
{
    char original[100];
    char password[100];
    char encoded[100];

    printf("Enter your message: ");
    fgets(original, sizeof(original), stdin);
    original[strcspn(original, "\n")] = '\0';

    printf("Enter a password: ");
    fgets(password, sizeof(password), stdin);
    password[strcspn(password, "\n")] = '\0'; // To remove newline char

    encode(original, password, encoded);
    printf("Your encoded message: %s", encoded);

    return 0;
}

void encode(char original[], char passwd[], char encoded[])
{
    // Handle empty case
    if (strlen(passwd) == 0)
    {
        strcpy(encoded, original);
        return;
    }

    // Build canonical set for a-z, A-Z and 0-9
    char canonical[62];
    for (int i = 0; i < 10; i++)
    {
        canonical[i] = '0' + i;
    }
    for (int i = 0; i < 26; i++)
    {
        canonical[10 + i] = 'A' + i;
    }
    for (int i = 0; i < 26; i++)
    {
        canonical[36 + i] = 'a' + i;
    }

    // Mixed char set build
    char mixed[62];
    char number = '9';
    for (int i = 1; i < 10; i += 2)
    {
        mixed[i] = number--;
    }
    for (int i = 60; i > 51; i -= 2)
    {
        mixed[i] = number--;
    }
    char lower_case = 'a';
    for (int i = 0; i < 51; i += 2)
    {
        mixed[i] = lower_case++;
    }
    char upper_case = 'A';
    for (int i = 61; i > 10; i -= 2)
    {
        mixed[i] = upper_case++;
    }

    // Reverse table lookup (char to index)
    int reverse[256];
    for (int i = 0; i < 256; i++)
    {
        reverse[i] = -1; // Set all to invalid
    }
    for (int i = 0; i < 62; i++)
    {
        reverse[(unsigned char)canonical[i] = i];
    }

    int passwd_index = 0;
    int passwd_len = strlen(passwd);
    for (int i = 0; original[i] != '\0'; i++)
    {
        if (original[i] == ' ')
        {
            encoded[i] = ' ';
        }
        else
        {
            // get the next char
            char p_char = passwd[passwd_index];
            passwd_index = (passwd_index + 1) % passwd_len;

            // find indexes for it
            int idx_char = reverse[(unsigned char)original[i]];
            int idx_pass = reverse[(unsigned char)p_char];

            if (idx_char == -1 || idx_pass == -1)
            {
                // if invalid then it is the same
                encoded[i] = original[i];
            }
            else
            {
                // calc the absolute difference
                int diff = idx_char - idx_pass;
                if (diff < 0)
                    diff = -diff;

                // encode from mixed set
                encoded[i] = mixed[diff];
            }
        }
    }
    // finish the string with \0
    encoded[strlen(original)] = '\0';
}