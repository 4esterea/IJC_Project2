// htab_for_each.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

void htab_for_each(const htab_t * t, void (*f)(htab_pair_t *data)){
    unsigned int count = 0;
    for (unsigned int i = 0; i < t->arr_size; i++) {
        struct htab_item *current = t->arr_ptr[i];
        while (current) {
            f(&(current->pair));
            current = current->next;
            count++;
        }
    }
}