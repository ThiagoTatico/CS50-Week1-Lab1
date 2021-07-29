// Calculates the smallest amount of coins for change.
#include <stdio.h>
#include <cs50.h>
#include <math.h>

int main(void)
{

    float dollars;

    do  //Prevents the input from being negative or zero
    {
        dollars = get_float("Change owed: ");
    }
    while (dollars <= 0);


    int cents = round(dollars * 100); //Covert to int cents
    int coins = 0; // Count how many coins were used

    while (cents >= 25) //Distribute the coins in the best way
    {
        cents -= 25;
        coins++;
    }
    while (cents >= 10)
    {
        cents -= 10;
        coins++;
    }
    while (cents >= 5)
    {
        cents -= 5;
        coins++;
    }
    while (cents >= 1)
    {
        cents -= 1;
        coins++;
    }

    printf("total coins: %i\n", coins);
}