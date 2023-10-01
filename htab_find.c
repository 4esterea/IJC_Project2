// htab_find.c
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

htab_pair_t * htab_find(htab_t * t, htab_key_t key){
    size_t hashKey = htab_hash_function(key);
    size_t arr_index = htab_hash_function(key) % t->arr_size;
    struct htab_item *temp = t->arr_ptr[arr_index];
    while (temp != NULL){
        if (htab_hash_function(temp->pair.key) == hashKey) return &(temp->pair);
        temp = temp->next;
    }
    return NULL;
}