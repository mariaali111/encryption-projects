#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main() {
    char *str = NULL;
    size_t size = 0;
    int key;

    // get plaintext
    printf("plaintext: ");
    getline(&str, &size, stdin);
    str[strcspn(str, "\n")] = 0;

    // get key
    printf("Enter key (number): ");
    scanf("%d", &key);

    for (int i = 0; i < strlen(str); i++)
    {
        if (isalpha(str[i]))
        {
            // preserve case
            if (islower(str[i]))
                str[i] = (str[i] - 'a' + key + 26) % 26 + 'a';
            if (isupper(str[i]))
                str[i] = (str[i] - 'A' + key + 26) % 26 + 'A';
        }
    }
    printf("ciphertext: %s", str);

    free(str);
    return 0;
}
