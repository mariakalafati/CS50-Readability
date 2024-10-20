#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <math.h>

int count_letters(string txt);
int count_words(string txt);
int count_sentences(string txt);
void grade(int i);

int main(void)
{

    string text = get_string("Text: ");
    float L = 100 * count_letters(text) / (float) count_words(text);
    float S =  100 * count_sentences(text) / (float) count_words(text);
    float index = 0.0588 * L - 0.296 * S - 15.8;
    int i = roundf(index);
    grade(i);
}

int count_letters(string txt)
{
    int letters = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {
        if (isalpha(txt[i]))
        {
            letters++;
        }

    }
    return letters;
}

int count_words(string txt)
{
    int words = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {

        if (isspace(txt[i]))
        {
            words++;
        }
    }
    if (words != 0)
    {
        words++;
    }
    return words;
}

int count_sentences(string txt)
{
    int sentences = 0;
    for (int i = 0, n = strlen(txt); i < n; i++)
    {

        if (txt[i] == '!' || txt[i] == '.' || txt[i] == '?')
        {
            sentences++;
        }
    }
    return sentences;
}

void grade(int i)
{
    if (i < 1)
    {
        printf("Before Grade 1\n");
    }
    else if (i >= 16)
    {
        printf("Grade 16+\n");
    }
    else
    {
        printf("Grade %i\n", i);
    }
}
