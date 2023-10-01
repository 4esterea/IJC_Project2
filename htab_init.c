// htab_init.c
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

htab_t *htab_init(size_t n){
    if (n == 0) return NULL;
    htab_t *new_htab = malloc(sizeof(htab_t));
    if (!(new_htab)) return NULL;
    new_htab->size = 0;
    new_htab->arr_size = n;
    new_htab->arr_ptr = malloc(sizeof(struct htab_item *) * n);
    for (size_t i = 0; i < n; i++) {
        new_htab->arr_ptr[i] = NULL; 
    }

    if (!(new_htab->arr_ptr)) return NULL;
    return new_htab;
}