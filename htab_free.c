// htab_free.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

void htab_free(htab_t * t){
    htab_clear(t);
    free(t->arr_ptr);
    free(t);
}