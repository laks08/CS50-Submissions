#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    long a = get_long("Number:");
    long a1=a;
    int sum=0;
    int sum1=0;
    int sum2=0;
    long n;
    int count=0;
    n = a;
    int b=0;
    int c = 0;
    do
    {
        n=n/10;
        ++count;
    }
    while (n != 0);
    //printf("count value: %i\n",count);

    for (int i=0; i<count+1; i++)
    {
        if((i%2) == 0)
        { //987654321
            b = a % 10;
            a = a / 10;
            sum = sum + b;
            //printf("Sum %i is %i and b is %i and a is %ld\n",i,sum,b,a);
        }
        else
        {
            c = (a % 10)*2;
            a = a / 10;
            int count1 = 0;
            int n1 = c;
            do
            {
                n1=n1/10;
                ++count1;
            }
            while (n1 != 0);
            if(count1==2)
            {
                int count2=0;
                while(count2<2)
                {
                    sum1 = sum1 + (c%10);
                    c = c/10;
                    count2++;
                }
            }
            else
            {
                sum2 = sum2 +(c%10);
            }
        }
    }
    int value = 0;
    // printf("%i\n",sum);
    // printf("%i\n",sum1);
    // printf("%i\n",sum2);

    value = sum + sum1 + sum2;
    // printf("%i\n",value);
    // printf("%i\n",count);

    if((value%10) == 0)
    {
        if(count == 15)
        {
            int p = a1/ pow(10,(count-2));
            if(p == 34 || p == 37)
            {
                printf("AMEX\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if( count == 16)
        {
            int p = a1/ pow(10,(count-1));
            int p1 = a1/pow(10,(count-2));
            if(p == 4)
            {
                printf("VISA\n");
            }

            else if((p1 == 51) || (p1 == 52) || (p1 == 53) || (p1 == 54) || (p1 == 55))
            {
                printf("MASTERCARD\n");
            }
            else
            {
                printf("INVALID\n");
            }
        }
        else if ( count == 13)
        {
            int p = a1/ pow(10,(count-1));
            if(p == 4)
            {
                printf("VISA\n");
            }
            else
            {
                printf("INVALID\n");
            }

        }
        else
        {
            printf("INVALID\n");
        }
    }
    else
    {
        printf("INVALID\n");
    }
}