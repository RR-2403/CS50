#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int POINTS[]={1,3,3,2,1,4,2,4,1,8,5,1,3,1,1,3,10,1,1,1,1,4,4,8,4,10};
int compute_score(string word);

int main(void)
{
    string n=get_string("Player1: ");
    string m=get_string("Player2: ");
    int length_n=strlen(n);
    int length_m=strlen(m);

    int score1= compute_score(n);
    int score2= compute_score(m);
    if(score1>score2)
    {
        printf("Player 1 wins!\n");
    }
    else if(score2>score1)
    {
        printf("Player 2 wins!\n");
    }
    else
    {
        printf("Tie!\n");
    }
}
int compute_score(string word)
{
    int n= strlen(word);
    int score=0;
    for(int x=0;x<n;x++)
    {
        if(isupper(word[x]))
        {
            score+=POINTS[word[x]- 'A'];
        }
        else if(islower(word[x]))
        {
            score+=POINTS[word[x]- 'a'];
        }
    }
    return score;
}
