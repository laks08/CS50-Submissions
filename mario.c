#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int a = 0;
    do
    {
        a = get_int("Enter number of rows:");
    }
    while ((a < 1) || (a > 8));
    //for loop i for rows, i=0 to avoid start printing equal to 'a' spaces.
    for (int i = 0; i < a ; i++)
    {
        //for loop j for rows, a-i for reducing the no. of spaces each cycle
        for (int j = 1; j < a - i; j++)
        {
            printf(" ");
        }
        //while for increasing # each row wrt to i, i+1 for cycle 0
        int count = 0;
        while (count < (i + 1))
        {
            printf("#");
            count++;
        }
        printf("  ");
        int count1 = 0;
        while (count1 < (i + 1))
        {
            printf("#");
            count1++;
        }
        // shift to next line after each row
        printf("\n");
    }
}