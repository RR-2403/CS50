#include <ctype.h>
#include <cs50.h>
#include <math.h>
#include <stdio.h>
#include <string.h>

int count_letters(string text);
int count_words(string text);
int count_sentences(string text);

int main(void)
{
    double L, S;
    string text = get_string("Text: ");

    int letters = count_letters(text);
    int words = count_words(text);
    int sentences = count_sentences(text);

    L= letters/(float)words * 100;
    S= sentences/(float)words * 100;

    int index = round(0.0588 * L - 0.296 * S - 15.8);

    if(index>16)
    {
        printf("Grade 16+\n");
    }
    else if(index<1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}

int count_letters(string text)
{
    int sum=0;
    int length=strlen(text);
    for (int x=0;x<length;x++)
    {
        if(isalpha(text[x]) != 0)
        {
            sum++;
        }
    }
    return sum;
}

int count_words(string text)
{
    int sum=0;
    int length=strlen(text);
    for (int x=0;x<length;x++)
    {
        if (text[x] == ' ')
        {
            sum++;
        }
    }
    sum++;
    return sum;
}

int count_sentences(string text)
{
    int sum = 0;
    int length = strlen(text);
    for (int x = 0; x < length; x++)
    {
        if (text[x] == '.' || text[x] == '?' || text[x] == '!')
        {
            sum++;
        }
    }
    return sum;
}
