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
    if(argc < 2 || argc > 2)
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }
    string l  = argv[1];
    //printf("l value:%c\n",l[0]);
    bool x =  only_digits(l);
    if(x==0)
    {
        int a = atoi(l);
        string s = get_string("plaintext:  ");
        int sl = strlen(s);
        //printf("sl:%i",sl);
        char ciphertext[sl];
        for(int i = 0; i < sl; i++)
        {
            ciphertext[i] = rotate(s[i],a);
        }
        printf("ciphertext: %s\n",ciphertext);
        return 0;
    }
    else
    {
        printf("Usage: ./caesar key\n");
        return 1;
    }

}
bool only_digits(string z)
{
    int n = strlen(z);
    int a=0;
    for(int i=0;i<n;i++)
    {
        if (isalpha(z[i]))
        {
            a++;
        }
    }

    if(a>0)
    {
        return 1;
    }
    else
    {
        return 0;
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
        int q = (int)c;
        int q1 = q - 97;
        int q2 = (q1+n)%26;
        int q3 = q2 + 97;
        char ci1 = (char)q3;
        return ci1;
    }
    else
    {
        return c;
    }
}

