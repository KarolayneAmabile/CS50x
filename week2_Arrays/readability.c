#include <ctype.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(char text[1000]);
int count_words(char text[1000]);
int count_sentences(char text[1000]);
float coleman_liau(int letters, int words, int sentences);

int main(void)
{
    //input
    char text[1000];
    printf("Text: ");
    gets(text);

    // funções para contagem
    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    //função do index de coleman liau
    int index = coleman_liau(letters, words, sentences);

    //output
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else
    {
        printf("Grade 16+\n");
    }
}

int count_letters(char text[1000])
{
    // para contar letras, programo o loop para considerar apenas alphanumericos e parar quando \0, caracteristica de fim de strings
    int letters = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] != '\0')
        {
            if (isalpha(text[i]))
            {
                letters++;
            }
        }
    }
    return letters;
}

int count_words(char text[1000])
{
    // para contar palavras, faço a contagem de espaços até o fim, e então somo +1
    int words = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == ' ' && text[i] != '\0')
        {
            words++;
        }
    }
    return words + 1;
}

int count_sentences(char text[1000])
{
    // para contar sentenças, conto a quantidade de vezes que os caracteres . ! e ? aparecem
    int sentences = 0;
    for (int i = 0; i < strlen(text); i++)
    {
        if (text[i] == '!' || text[i] == '?' || text[i] == '.')
        {
            sentences++;
        }
    }
    return sentences;
}

float coleman_liau(int letters, int words, int sentences)
{
    float L = ((float)letters / (float)words) * 100.0;
    float S = ((float) sentences / (float)words) * (float) 100.0;

    float index = 0.0588 * L - 0.296 * S - 15.8;
    return round(index);
    // foi preciso adicionar a biblioteca math.h, pois o aredondamento padrão de int não estava funcionando para todos os casos
    // apesar dos argumentos serem integers, é preciso fazer o calculo considerando os decimais, por isso o (float)
}
