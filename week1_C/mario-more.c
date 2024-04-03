#include <stdio.h>

int main(void)
{
    int length = 0;
    do 
    {
        printf("Height size: ");
        scanf("%i", &length);
    } 
    while (length > 8 || length < 1);  

    for (int hight = 0; hight < length; hight++)
    {
        for (int leftside = 0; leftside < length; leftside++) 
        {
            if (leftside < length - hight - 1) 
            {
                printf(" ");
            } else {
                printf("#");
            }
        }
        printf("  "); // gap
        for (int rightside = 0; rightside < length; rightside++)
        {
            if (rightside >= length - hight - 1)
            {
            printf("#");
            }
        }
        printf("\n");
    }
    return 0;
}

// We can divide this problem into three parts: printing the left-side pyramid, the gap between them, and the right-side pyramid.
// For this, we just need to create a loop that iterates through each row and prints them separately.
// For the left side, we'll follow the same steps as before in the "mario-less" version. Starting from 0, while the width is less than the length minus height minus 1, we'll print blank spaces. Otherwise, we'll print hashes.
// To separate the two pyramids, we'll always print two blank spaces between them.
// For the right side, we'll do the opposite of what we do for the left side. So, when the width is greater than or equal to the length minus height minus 1, we'll print hashes.
// Remember that the actual input is equal to the height of the figure we want to create, but the final width is equal to height * 2 + 2, which accounts for the width of the left side (height), the gap (2 spaces), and the width of the right side (height).
