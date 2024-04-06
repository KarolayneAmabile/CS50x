#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getIndex (char letter);
char substitution (int index, char key[26]);
void makeCyphertext(char key[26], char text[200]);

int main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("./substitution key\n");
        return 1;
    }

    int key_len = strlen(argv[1]) + 1;
    char key[key_len];
    strncpy(key, argv[1], key_len - 1);
    key[key_len - 1] = '\0'; 

    if (key_len != 27)
    {
        printf("Key must contain 26 characters.\n");
        return 1;
    }

    for (int i = 0; i < 26; i++)
    {
        if (!isalpha(key[i]))
        {
            printf("./substitution key\n");
            return 1;
        }
    }

    char text[300];
    printf("plaintext: ");
    gets(text);
    makeCyphertext(key, text);
    return 0;
}

int getIndex (char letter)
{   
    char alphabet[26] = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int index = -1;

    if(isalnum(letter))
    {
        letter = toupper(letter);
        for (int i = 0; i < 26; i++)
        {
            if (alphabet[i] == letter)
            {
                index = i;
                break;
            }
        }
    } 
    return index;
}

char substitution (int index, char key[26])
{
    char letter = key[index];
    return letter;
}

void makeCyphertext(char key[26], char text[200])
{
    char cyphetext[200];
    for (int i = 0; i < strlen(text); i++)
    {
        if (isalpha(text[i]))
        {
            int index = getIndex(text[i]);
            cyphetext[i] = substitution(index, key);
            if (islower(text[i]))
            {
                cyphetext[i] = tolower(cyphetext[i]);
            }
        } else {
            cyphetext[i] = text[i];
        }
    }
    printf("cyphertext: %s", cyphetext);
}