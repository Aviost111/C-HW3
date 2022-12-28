#include "functions.h"
#include <stdio.h>
#include <string.h>

#define LINE 256
#define WORD 30
#define TEXT 250 // number of lines in the text <= 250

int main() {
    int len=1;
    char word[LINE] = {0};
    getWord(word);
    printf("%s\n",word);
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

