#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

void encipher(char *key, char *plaintext);

int main(int argc, char *argv[])
{
    // get key
    char *key = argv[1];

    // validate key
    if (argc != 2)
    {
        printf("Usage: ./substitution.exe key\n");
        return 1;
    }
    // check key length
    if (strlen(key) != 26)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }
    // check for non-alphabetic characters
    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("Key must only contain alphabetic characters.\n");
            return 1;
        }
    }
    // check for repeated characters (case insensitive)
    for (int i = 0; i < 26; i++)
    {
        for (int j = i + 1; j < 26; j++)
        {
            if (tolower(key[i]) == tolower(key[j]))
            {
                printf("Key must not contain repeated characters.\n");
                return 1;
            }
        }
    }
    // get plaintext
    char *plaintext = NULL;
    size_t size = 0;
    
    printf("plaintext: ");
    getline(&plaintext, &size, stdin);
    plaintext[strcspn(plaintext, "\n")] = 0;

    // encipher
    encipher(key, plaintext);

    free(plaintext);
}

void encipher(char *key, char *plaintext)
{
    printf("ciphertext: ");
    
    // for each alphabetic character, determine what letter it maps to
    for (int i = 0; plaintext[i] != '\0'; i++)
    {
        if (isalpha(plaintext[i]))
        {
            // preserve case
            if (isupper(plaintext[i]))
            {
                int index = plaintext[i] - 'A';
                char mapped = key[index];
                mapped = toupper(mapped);
                printf("%c", mapped); // print ciphertext
            }
            else if (islower(plaintext[i]))
            {
                int index = plaintext[i] - 'a';
                char mapped = key[index];
                mapped = tolower(mapped);
                printf("%c", mapped); // print ciphertext
            }
        }
        // leave non-alphabetic characters as-is
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
}
