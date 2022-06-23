#include <stdio.h>
#include <cs50.h>

int main(void)
{
    //Taking input from user
    string name = get_string("What is your name?\n");
    //Output
    printf("hello %s\n", name);
}