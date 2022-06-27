#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

int count_letters(string s);
float count_words(string s);
int count_sentences(string s);

int main(void)
{
    string text = get_string("Text:");
    int x = count_letters(text);
    float w = count_words(text);
    int y = count_sentences(text);
    float l = (x / w) * 100;
    float s = (y / w) * 100;

    // printf("%i\n",x);
    // printf("%f\n",w);
    // printf("%i\n",y);
    // printf("%f\n",l);
    // printf("%f\n",s);

    float indexrnd = (0.0588 * l) - (0.296 * s) - 15.8;
    int index = (int) round(indexrnd);
    //printf("Index:%i\n",index);
    if (index > 1 && index < 16)
    {
        printf("Grade %i\n", index);
    }
    else if (index >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Before Grade 1\n");
    }

}

int count_letters(string s)
{
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n; i++)
    {
        int a = (int)s[i];
        if ((a > 64 && a < 91) || (a > 96 && a < 123))
        {
            sum++;
        }
    }
    return sum;
}

float count_words(string s)
{
    int n = strlen(s);
    int sum = 0;
    for (int i = 0 ; i < n; i++)
    {
        if (s[i] == ' ')
        {
            sum++;
        }
    }
    sum = sum + 1;
    return sum;
}

int count_sentences(string s)
{
    int n = strlen(s);
    int sum = 0;
    for (int i = 0; i < n ; i++)
    {
        if ((s[i] == '.') || (s[i] == '!') || (s[i] == '?'))
        {
            sum++;
        }
    }
    return sum;
}