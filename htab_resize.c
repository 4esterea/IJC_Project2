// htab_resize.c
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

void htab_resize(htab_t *t, size_t newn){
    t->arr_ptr = realloc(t->arr_ptr, sizeof(struct htab_item *) * newn);
    t->arr_size = newn;
}