//sets the educational level of the text
#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

// Function prototypes:
int get_letters(string letters);
int get_words(string words);
int get_sentences(string sentences);
int get_Glevel(int letters, int words, int sentences);
void print_Glevel(int Glevel);

int main(void)
{
    string TEXT = get_string("Text: "); //Request the user for text

    int numberOf_letters = get_letters(TEXT); //Returns the number of letters in the string

    int numberOf_words = get_words(TEXT); //Returns the number of words in the string

    int numberOf_sentences = get_sentences(TEXT); //Returns the number of sentences in the string

    int grade_level = get_Glevel(numberOf_letters, numberOf_words, numberOf_sentences); //Returns Grade level
    
    print_Glevel(grade_level); //Returns print of Grade level
}



//FUNCTIONS:----------------------------------------------------------------------------------------------------------------------------------------------------------------

//letter counter.
int get_letters(string letters)
{
    int count1 = 0;

    for (int i = 0, n = strlen(letters); i < n; i++)
    {
        if (isalpha(letters[i]))
        {
            count1++;
        }
    }
    return count1;
}

//Words counter.
int get_words(string words)
{
    int count2 = 0;
    for (int i = 0, n = strlen(words); i < n; i++)
    {

        if (words[i] == ' ')
        {
            count2++;
        }

    }
    return count2 + 1;
}

//Sentences counter.
int get_sentences(string sentences)
{
    int count3 = 0;
    for (int i = 0, n = strlen(sentences); i < n; i++)
    {
        if (sentences[i] == '.' || sentences[i] == '!' || sentences[i] == '?')
        {
            count3++;
        }
    }
    return count3;
}

//Grade level cauculate
int get_Glevel(int letters, int words, int sentences)
{
    float L = (letters / (float) words) * 100;

    float S = (sentences / (float) words) * 100;

    return round(0.0588 * L - 0.296 * S - 15.8);
}

//Print grade level
void print_Glevel(int Glevel)
{
    if (Glevel >= 16)
    {
        printf(" Grade 16+\n");
    }
    else if (Glevel <= 1)
    {
        printf("Before Grade 1\n");
    }
    else
    {
        printf("Grade %i\n", Glevel);
    }
}