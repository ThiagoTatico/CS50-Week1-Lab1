//Converter to Caesar cipher 
#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
#include <stdlib.h>

//Restrictions
int main(int argc, string argv[])
{
    if (argc != 2) // check for command line argument
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    
    for (int q = 0, n = strlen(argv[1]); q < n; q++) //check if the key characters are numbers
    {
        if (isalpha(argv[1][q]))
        {
            printf("Usage: ./caesar key\n");
            return 1;
        }
    }
//----------------------------------------------------------------------------------------------------------------------

//Applying the cipher
    int k = atoi(argv[1]) % 26;
    string plaintext = get_string("Plaintext: ");
 
    printf("Ciphertext: ");
    
    for (int i = 0, n = strlen(plaintext); i < n; i++)
    {
        if (!isalpha(plaintext[i]))
        {
            printf("%c", plaintext[i]);
            continue;
        }
        
        int ascii_offset = isupper(plaintext[i]) ? 65 : 97; //check which ASCII offset
        
        int pi = plaintext[i] - ascii_offset;
        int ci = (pi + k) % 26;
        
        printf("%c", ci + ascii_offset);
    }
    
    printf("\n");
    return 0;
}