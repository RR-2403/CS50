#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int height;
    do
    {
        height=get_int("HEIGHT= ");
    }
    while(height<1 || height>8);
    for(int row=0; row<height; row++)
    {
        for(int spacing=0; spacing<height-row-1; spacing++)
        {
            printf(" ");
        }
        for(int column=0; column<=row; column++)
        {
            printf("#");
        }
        printf("\n");
    }
}
