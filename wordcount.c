// wordcount.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdio.h>
#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

#define HTAB_SIZE 5
#define MAX_WORD_LENGTH 255

void print_contents(htab_pair_t *pair);

int read_word(char *s, int max, FILE *f);

int main() {
    htab_t *t = htab_init(HTAB_SIZE);
    if (!(t)) {
        fprintf(stderr, "htab_init Allocation error\n");
        exit(1);
    }
    char buffer[MAX_WORD_LENGTH];
    htab_pair_t *add = NULL;
    while (read_word(buffer, MAX_WORD_LENGTH, stdin) != EOF) {
        add = htab_lookup_add(t, buffer);
        add->value++;
    }
    add = htab_lookup_add(t, buffer);
    add->value++;
    htab_for_each(t, &print_contents);
    htab_free(t);
    return 0;
}

void print_contents(htab_pair_t *pair){
    printf("%s - %d\n", pair->key, pair->value);
}