#include "functions.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define TEXT 250 // number of lines in the text <= 250

int getLine(char s[]) {
    int count=0;
    for (int i = 0; i < LINE; ++i) {
        if((s[i] = getchar())==EOF){
            return 0;
        }
        count++;
        if ((s[i] == '\n') || (s[i] == '\r')) {
            s[i] = '\0';
            break;
        }
    }
    return count;
}

int getWord(char w[]) {
    int count=0;
    for (int i = 0; i < WORD; ++i) {
        if((w[i] = getchar())==EOF){
            if(count==0){
                return 0;
            }else{
                w[i]=' ';
            }
        }
        count++;
        if ((w[i] == '\n') || (w[i] == '\t') || (w[i] == ' ') || (w[i] == '\r')) {
            w[i] = '\0';
            count--;
            break;
        }
    }
    return count;
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

int print_lines(char *str) {
    char line[LINE] = {0};
    int len=getLine(line);
    if(len==0){
        return 0;
    }
    if (substring(line, str)) {
        printf("%s\n", line);
    }
    return 1;
}

int print_similar_words(char *str) {
    char word[WORD] = {0};
    int len=getWord(word);
    if(len==0){
        return 0;
    }
    if (similar(word, str, 1)) {
        printf("%s\n", word);
    }
    return 1;
}



int main() {
    int len=1;
    char word[LINE] = {0};
    getWord(word);
    printf("%s\n",word);//remove before testing
    char searchOption = getchar();
    getchar();
    getchar();

    if (searchOption == 'a') {
        while (len) {
            len=print_lines(word);
        }

    } else if (searchOption == 'b') {
        while (len) {
            len=print_similar_words(word);
        }
    }
}

