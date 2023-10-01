// htab_clear.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

void htab_clear(htab_t * t){
    for (unsigned int i = 0; i < t->arr_size; i++) {
        struct htab_item *current = t->arr_ptr[i];
        while (current) {
            struct htab_item *temp = current->next;
            free((char*)current->pair.key);
            free((char*)current);
            t->size--;
            current = temp;
        }
        t->arr_ptr[i] = NULL;
    }
}