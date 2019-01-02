#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

int main(int argc, string argv[])
{

    int key;

    if (argc != 2)
    {
        printf("Usage: ./vigenere key\n");
        return 1;
    }
    else
    {

        for (int j = 0, k = strlen(argv[1]); j < k; j++)
        {
            if (!(isalpha(argv[1][j])))
            {
                printf("Key must be alphabetical\n");
                return 1;
            }
        }
        printf("plaintext: ");
        string s = get_string();
        printf("ciphertext: ");
        int l =  strlen(argv[1]);

        for (int i = 0, n = strlen(s); i < n; i++)
        {

            key = toupper(argv[1][i % l]);
            key = key - 65;

           if (isupper(s[i]))
           {
                s[i] = s[i] - 65;
                s[i] = ((s[i]+key) % 26);
                s[i] = s[i] + 65;
                printf("%c", s[i]);
           }
           else if (islower(s[i]))
           {
                s[i] = s[i] - 97;
                s[i] = ((s[i]+key) % 26);
                s[i] = s[i] + 97;
                printf("%c", s[i]);
           }
           else if (!(isalpha(s[i])))
           {
               printf("%c", s[i]);
           }

        }


    }

    printf("\n");


}

