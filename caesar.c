#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    //printf("argc val:%i\n",argc);
    if (argc < 2 || argc > 2) // condition to check if arguments are not more than 1
    {
        printf("Usage: ./caesar key\n");
        return 1; //quit program if otherwise
    }
    string l  = argv[1]; //putting cmnd line argmt in a string
    //printf("l value:%c\n",l[0]);
    bool x =  only_digits(l); //calling fn o_ds to check if passing only digits
    if (x == 0) //if true continue
    {
        int a = atoi(l); //convert string to int
        string s = get_string("plaintext:  ");
        int e = strlen(s); //string length
        //printf("E:%i",e);
        char ciphertext[e]; // define char arr
        for (int i = 0; i < e; i++)
        {
            ciphertext[i] = rotate(s[i], a); // callign rotate fn to cipher
        }
        printf("ciphertext: ");
        for (int k = 0 ; k < e; k++)
        {
            printf("%c", ciphertext[k]);// print out
        }
        printf("\n");
        return 0;
    }
    else//if false quit
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
bool only_digits(string z) //digit check
{
    int n = strlen(z);
    int a = 0;
    for (int i = 0; i < n; i++)
    {
        if (isalpha(z[i]))
        {
            a++;
        }
    }

    if (a > 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

char rotate(char c, int n) // cipher section
{
    if (isupper(c))
    {
        int p = (int)c;
        int p1 = p - 65;
        int p2 = (p1 + n) % 26;
        int p3 = p2 + 65;
        char ci = (char)p3;
        return ci;
    }
    else if (islower(c))
    {
        int q = (int)c;
        int q1 = q - 97;
        int q2 = (q1 + n) % 26;
        int q3 = q2 + 97;
        char ci1 = (char)q3;
        return ci1;
    }
    else
    {
        return c;
    }
}

