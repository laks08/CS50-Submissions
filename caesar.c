#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

bool only_digits(string s);
char rotate(char c, int n);

int main(int argc, string argv[])
{
    string l  = argv[1];
    bool x = only_digits(l);
    return x;
    int a = atoi(l);
    string s = get_string("plaintext:");
    int sl = strlen(s);
    char ciphertext[sl];
    for(int i = 0; i<sl; i++)
    {
       ciphertext[i] = rotate(s[i],a);
    }
     printf("Cipher:%s\n",ciphertext);
}

bool only_digits(string s)
{

    if(isdigit(s[0]))
    {
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
}

char rotate(char c, int n)
{
    if (isupper(c))
    {
        int p = (int)c;
        int p1 = p - 65;
        int p2 = (p1+n)%26;
        int p3 = p2 + 65;
        char ci = (char)p3;
        return ci;
    }
    else if (islower(c))
    {
        int p = (int)c;
        int p1 = p - 97;
        int p2 = (p1+n)%26;
        int p3 = p2 + 97;
        char ci = (char)p3;
        return ci;
    }
    else
    {
        return c;
    }
}

