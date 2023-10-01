// io.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdio.h>
#include <stdbool.h>
#include <ctype.h>


int read_word(char *s, int max, FILE *f) {
    char a = 'a';
    bool overflow = false;
    int i = 0;
    while ((a = getc(f)) != EOF && isspace(a)) {}
    if (a == EOF) {
        return EOF;
    }
    else {
        s[i] = a;
        i++;
    }
    while ((a = getc(f)) != EOF && !(isspace(a))) {
        if (i == max - 1) {
            overflow = true;
            break;
        }
        if (a == '\n') continue;
        else {
            s[i] = a;
            i++;
        }
    }
    s[i] = '\0';
    if (overflow) {
        fprintf(stderr, "Word is too long\n");
    }
    if (a == EOF) {
        return EOF;
    }
    return i;
}