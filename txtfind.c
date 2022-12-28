#include "functions.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define TEXT 250 // number of lines in the text <= 250

void getLine(char s[]) {
    printf("Enter a line character by character :"); // delete this line before submission
    for (int i = 0; i < LINE + 1; ++i) {
        s[i] = getchar();
        if ((s[i] == '\n') || (s[i] == '\r')) {
            s[i + 1] = '\0';
            break;
        }
    }
}

void getWord(char w[]) {
    for (int i = 0; i < WORD + 1; ++i) {
        w[i] = getchar();
        if ((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' ') || (w[i] == '\r')) {
            w[i + 1] = '\0';
            break;
        }
    }
}

int substring(char *str1, char *str2) {
    int len1 = strlen(str1), len2 = strlen(str2);
    if (len1 < len2) {
        return 0;
    }
    for (int i = 0; i < len1 - len2; ++i) {
        if (*(str1 + i) == *str2) {
            for (int j = 1; j < len2; ++j) {
                if (*(str1 + i + j) != *(str2 + j)) {
                    i = i + j - 1;
                    break;
                }
                if (j == len2 - 1) {
                    return 1;
                }
            }
        }
    }
    return 0;
}

int similar(char *s, char *t, int n) {
    int lenS = strlen(s), lenT = strlen(t), counter = 0, indexT = 0;
    for (int i = 0; i < lenS; ++i) {
        if (*(s + i) == *(t + indexT)) // s[i] == t[indexT]
        {
            indexT++;
            if (indexT == lenT) {
                return 1;
            }
        } else {
            counter++;
            if (counter == n + 1) {
                return 0;
            }
        }
    }
    return 0;
}

void print_lines(char *str) {
    char line[LINE] = {0};
    getLine(line);
    if (substring(line, str)) {
        printf("%s\n", line);
    }
}

void print_similar_words(char *str) {
    char word[WORD] = {0};
    getWord(word);
    if (similar(word, str, 1)) {
        printf("%s\n", word);
    }
}
