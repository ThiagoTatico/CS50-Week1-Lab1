//Calculates how many years it will take to reach the desired llama population
#include <cs50.h>
#include <stdio.h>

int main(void)
{

    int initialP;
    do
    {
        initialP = get_int("Start size: "); //Get a positive integer greater than or equal to 9
    }
    while (initialP < 9);

    int finalP;
    do
    {
        finalP = get_int("End size: "); //Get a positive integer greater than the initial population
    }
    while (finalP < initialP);

    int ip = initialP;
    int fp = finalP;
    int calc = 0;
    do
    {
        ip = ip + ((int) ip / 3) - ((int) ip / 4);  //calculate how many years for the desired population
        calc++;
    }
    while (ip < fp);


    if (initialP == finalP) //if the values ip and fp are equal, change the counter to 0 years
    {
        calc = 0;
    }

    printf("Years: %i\n", calc);

}