#include "functions.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
// #define TEXT 250 // number of lines in the text <= 250

int getLine(char s[])
{
    int count = 0;
    for (int i = 0; i < LINE; ++i)
    {
        if ((s[i] = getchar()) == EOF)
        {
            return 0;
        }
        count++;
        if ((s[i] == '\n') || (s[i] == '\r'))
        {
            s[i] = '\0';
            break;
        }
    }
    return count;
}

int getWord(char w[])
{
    int count = 0;
    for (int i = 0; i < WORD; ++i)
    {
        if ((w[i] = getchar()) == EOF)
        {
            if (count == 0)
            {
                return 0;
            }
            else
            {
                w[i] = ' ';
            }
        }
        count++;
        if ((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' ') || (w[i] == '\r'))
        {
            w[i] = '\0';
            count--;
            break;
        }
    }
    return count;
}

int substring(char *str1, char *str2)
{
    if (strstr(str1, str2) != NULL)
        return 1;
    else
        return 0;
}

int similar(char *s, char *t, int n)
{
    int lenS = strlen(s), lenT = strlen(t);
    int counter = 0, indexS = 0, indexT = 0;
    if (lenS == lenT || lenS - n == lenT)
    {
        for (int i = 0; i < lenS; i++)
        {
            if (s[indexS] == t[indexT])
            {
                indexT++;
                indexS++;
                continue;
            }
            if (s[indexS] != t[indexT])
            {
                indexS++;
                counter++;
            }
            if (counter > n)
            {
                return 0;
            }
        }
        return 1;
    }
    else
        return 0;
}

int print_lines(char *str)
{
    char line[LINE] = {0};
    int len = getLine(line);
    if (len == 0)
    {
        return 0;
    }
    if (substring(line, str))
    {
        printf("%s\n", line);
    }
    return 1;
}

int print_similar_words(char *str)
{
    char word[WORD] = {0};
    int len = getWord(word);
    if (len == 0)
    {
        return 0;
    }
    if (similar(word, str, 1))
    {
        printf("%s\n", word);
    }
    return 1;
}
