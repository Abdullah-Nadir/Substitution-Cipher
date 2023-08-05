#include <cs50.h>
#include <ctype.h>
#include <stdio.h>
#include <string.h>

// Functions Prototypes
bool key_validity(string key);
void cipher(string key, string plaintext);

int main(int argc, string argv[])
{
    if (argc == 2)
    {
        // Check for validity
        bool valid = key_validity(argv[1]);

        if (valid)
        {
            // Substitution cipher functionality
            string p = get_string("Plaintext:  ");

            // Converting Plaintext into ciphertext & printing on screen
            cipher(argv[1], p);
            return 0;
        }
        else
        {
            return 1;
        }
    }
    else
    {
        printf("Usage: ./substitution key\n");
        return 1;
    }
}

// Checking for the Validity of the Key
bool key_validity(string key)
{
    int length = strlen(key);
    bool valid = false;
    if (length == 26)
    {
        // Further Validity Checking
        int repeatition_checker[26] = {0};
        for (int i = 0; i < length; i++)
        {
            if (isalpha(key[i]))
            {
                // Further Validity Checking (Non-Repeated Characters)
                int index = islower(key[i]) ? (key[i] - 'a') : (key[i] - 'A');

                if (repeatition_checker[index] == 0)
                {
                    repeatition_checker[index] = 1;
                }
                else
                {
                    printf("Key must contain each alphabatical character only once.\n");
                    valid = false;
                    return valid;
                }
            }
            else
            {
                printf("Key can only contain Alphabatical Characters.\n");
                valid = false;
                return valid;
            }
        }

        valid = true;
        return valid;
    }
    else
    {
        printf("Key must contain 26 characters.\n");
        valid = false;
    }

    return valid;
}

void cipher(string key, string plaintext)
{
    int l = strlen(plaintext);
    char ciphertext[l];

    for (int i = 0; i <= l; i++)
    {
        if (isalpha(plaintext[i])) // Functionality for alphabetical characters
        {
            if (islower(plaintext[i])) // For lowercase
            {
                ciphertext[i] = tolower(key[plaintext[i] - 'a']);
            }
            else // For uppercase
            {
                ciphertext[i] = toupper(key[plaintext[i] - 'A']);
            }
        }
        else // For non-alphabetical characters
        {
            ciphertext[i] = plaintext[i];
        }
    }

    // Printing the results on screen
    printf("ciphertext: %s\n", ciphertext);
}
