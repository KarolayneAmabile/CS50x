#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char rotate(char plaintext[1000], int k);

int main(int argc, char *argv[])
{
    //conta os argumentos da linha de comando
    if (argc != 2)
    {
        printf("./ceasar key\n");
        return 1;
    }

    //armazena a chave para criptografar
    int k = atoi(argv[1]);

    //verifica se o argumento é uma string
    if (k == 0)
    {
        printf("./ceasar key\n");
        return 1;
    }
    char plaintext[1000];
    printf("plaintext: ");
    gets(plaintext);

    printf("ciphertext: ");
    char cyphertext = rotate(plaintext, k);

}

char rotate(char plaintext[1000], int k)
{
    for (int i = 0; i < strlen(plaintext); i++)
    {
        if (islower(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'a') + k) % 26) + 'a');
        }
        else if (isupper(plaintext[i]))
        {
            printf("%c", (((plaintext[i] - 'A') + k) % 26) + 'A');
        }
        else
        {
            printf("%c", plaintext[i]);
        }
    }
    printf("\n");
    return 0;
}
//usamos o calculo: (atual posição da letra - posição da letra a) + chave) % 26 + 'a'