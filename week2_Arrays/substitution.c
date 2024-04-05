#include <stdio.h>
#include <string.h>
#include <ctype.h>

int getIndex (char letter);
char substitution (int index, char key[26]);
void makeCyphertext(char key[26], char text[200]);

int main(void)
{
    char key[26] = "NQXPOMAFTRHLZGECYJIUWSKDVB";
    char text[20] = "Ola a todos!";
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