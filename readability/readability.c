#include<ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
int count_letters(string text);
int count_words(string text);
int count_senetences(string text);
int main(void)

{

int count_letters = 0;
int count_words = 1;
int count_sentences = 0;

   string text = get_string("Text:");


    int text_length = strlen(text);
    for( int i = 0; i < text_length ;  i++)
    {
        if(isalpha(text[i]) )
        {
          count_letters++;
        }
    }
  // printf("%i Letters\n",count_letters);

        for (int i = 0; i < text_length; i++)
        {
            if (isspace(text[i]))
            {
                count_words++;
            }
        }
    //printf("%i Words\n",count_words);

    for ( int i = 0; i < text_length; i++)
    {
        if (text[i] == '.' || text[i] == '?' || text[i] == '!')
        {
            count_sentences++;
        }
    }
    //printf("%i Sentences\n", count_sentences);
    float calculation = (0.0588 * count_letters / count_words * 100) - (0.296 * count_sentences / count_words * 100) - 15.8;
    int index = round(calculation);
    if (index < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (index > 16)

    {
        printf("Grade 16+");
    }
    else
    {
        printf("Grade %i\n", index);
    }
}



