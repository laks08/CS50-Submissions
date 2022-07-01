#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

bool arg_check(string str);

int main(int argc, string argv[])
{
    if (argc < 2 || argc > 2)
    {
        printf("Error! Enter 1 key!\n");
        return 1;
    }
        string s = argv[1];
        int n = strlen(s);// string key check
        for(int i=0; i<n ; i++)
        {
            s[i] = toupper(s[i]);
        }
        bool x = arg_check(s);
        if (x==1)
        {
            //printf("Error! Enter correct key!\n");
            return x;
        }
        else
        {
            string plaintext = get_string("plaintext:");
            int n1 = strlen(plaintext);
            char c[n1];
            for (int i =0; i < n1; i++)
            {
                int a = (int)plaintext[i];
                if ((a > 64) && (a < 91))
                {
                    int b = a - 65;
                    c[i] = s[b];
                }
                else if ((a > 96) && (a < 123))
                {
                    int f = a - 97;
                    c[i] = tolower(s[f]);
                }
                else
                {
                    c[i] = plaintext[i];
                }
            }
            printf("ciphertext:");
            for (int j = 0; j < n1; j++)
            {
                printf("%c",c[j]);
            }
            printf("\n");
        }
}

bool arg_check(string str)
{
    int n = strlen(str);
    int check = 0;
    int check1 = 0;

    for (int i = 0; i<n; i++)
    {
        for (int j = i+1; j < n;j++)
        {
            if(str[j] == str[i])
            {
                check = 1;
            }
            else
            {
                check = 0;
            }
        }
    }

    for ( int k = 0; k<n ; k++)
    {
        if(!isalpha(str[k]))
        {
            check1 = 1;
        }
        else
        {
            check1 = 0;
        }
    }

    if(n==26 && check != 1 && check1 !=1)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}