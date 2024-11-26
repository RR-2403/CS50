#include <cs50.h>
#include <stdio.h>

int calculate_quarter(int cents);
int calculate_dime(int cents);
int calculate_nickel(int cents);
int calculate_penny(int cents);

int main(void)
{
    int change=get_int("CHANGE OWED: ");
    while(change<=0)
    {
        change=get_int("CHANGE OWED: ");
    }
    int quarter=calculate_quarter(change);
    change=change-quarter*25;
    int dime=calculate_dime(change);
    change=change-dime*10;
    int nickel=calculate_nickel(change);
    change=change-nickel*10;
    int penny=calculate_penny(change);
    change=change-penny*1;

    int coins= quarter+dime+nickel+penny;
    printf("%i\n",coins);
}
int calculate_quarter(int cents)
{
    return cents/25;
}
int calculate_dime(int cents)
{
    return cents/10;
}
int calculate_nickel(int cents)
{
    return cents/5;
}
int calculate_penny(int cents)
{
    return cents/1;
}
