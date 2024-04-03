#include <stdio.h>

int main(void)
{
    int length = 0;
    do 
    {
        printf("Hight size: ");
        scanf("%i", &length);
    } 
    while (length > 8 || length < 1); // defines the input parameters 

    for (int hight = 0; hight < length; hight++) // scrolls through column
    {
        for (int width = 0; width < length; width++) // scrolls through lines
        {
            if (width < length - hight - 1) // if width is less then length minus hight minus 1, then we gonna printf blanks spaces
            {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("\n");
    }
}