#include "functions.h"
#include <stdio.h>
#include <string.h>
#define LINE 256
#define WORD 30

int getLine(char s[])
{
    int count = 0;
    printf("Enter a line character by character :"); // delete this line before submission
    for (int i = 0; i < LINE; ++i)
    {
        s[i] = getchar();
        count++;
        if (s[i] == '\n')
        {
            s[i + 1] = '\0';
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
        w[i] = getchar();
        count++;
        if ((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' '))
        {
            w[i + 1] = '\0';
            break;
        }
    }
    return count;
}

int substring(char *str1, char *str2)
{
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 < len2)
    {
        return 0;
    }
    for (int i = 0; i < len1 - len2; ++i)
    {
        if (*(str1 + i) == *str2)
        {
            for (int j = 1; j < len2; ++j)
            {
                if (*(str1 + i + j) != *str2 + j)
                {
                    i = i + j - 1;
                    break;
                }
                if (j == len2 - 1)
                {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int is_substring(char *s1, char *s2)
{

    int len1 = strlen(s1);
    int len2 = strlen(s2);
    int j;
    for (int i = 0; i < len1 - len2; i++)
    {
        for (j = 0; j < len2; j++)
        {
            if (s1[i + j] != s2[j])
            {
                i = i + j - 1;
                break;
            }
        }
        if (j == len2)
        {
            return 1;
        }
    }
    return 0;
}

int similar(char *s, char *t, int n)
{
    int lenS = strlen(s), lenT = strlen(t), counter = 0, indexT = 0;
    for (int i = 0; i < lenS; ++i)
    {
        if (*(s + i) == *(t + indexT)) //s[i] == t[indexT]
        {
            indexT++;
            if (indexT == lenT)
            {
                return 1;
            }
        }
        else
        {
            counter++;
            if (counter == n + 1)
            {
                return 0;
            }
        }
    }
}

void print_lines(char *str)
{
    char *line = NULL;

    
}

void print_similar_words(char *str)
{

}

int main(){
    //fgets for the word
    char word[WORD];
    fgets(word, sizeof(word), stdin);
    //"read" the space
    char space;
    scanf("%c",&space);
    //scanf for a or b
    char searchOption;
    scanf("%c",searchOption);
    if(searchOption == 'a'){
    
    
    }
    else if (searchOption == 'b'){

    }
}
