//do mario's ladder
#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int hei, reps, space, hashtag;

    do
    {
        hei = get_int("Height: ");
    }
    while (hei < 1 || hei > 8);


    for (reps = 0; reps < hei; reps++)  //Define how many times will be repeated the below
    {
        for (space = 0; space < hei - reps - 1; space++)  //Make the spacing
        {
            printf(" ");
        }

        for (hashtag = 0; hashtag <= reps; hashtag++)  //Define how many # will be printed per line before breaking it
        {
            printf("#");
        }

        printf("  ");

        for (hashtag = 0; hashtag <= reps; hashtag++)  //Define how many # will be printed per line before breaking it
        {
            printf("#");
        }

        printf("\n");

    }
}