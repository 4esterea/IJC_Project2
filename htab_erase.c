// htab_erase.c
// Řešení IJC-DU2, příklad 2, 18.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include "htab.h"
#include "pr_htab.h"

bool htab_erase(htab_t * t, htab_key_t key){
    htab_pair_t *target = htab_find(t, key);
    if (!(target)) return false;
    size_t hashKey = htab_hash_function(key) % t->arr_size;
    if ( t->arr_ptr[hashKey]->pair.key == key ){
        struct htab_item *temp = t->arr_ptr[hashKey]->next;
        free((char*)t->arr_ptr[hashKey]->pair.key);
        free((char*)t->arr_ptr[hashKey]);
        t->arr_ptr[hashKey] = temp;
        t->size--;
        return true;
    }
    struct htab_item *previous = t->arr_ptr[hashKey];
    struct htab_item *current = t->arr_ptr[hashKey]->next;
    while (current) {
        if ( current->pair.key == key){
            previous->next = current->next;
            free((char*)current->pair.key);
            free((char*)current);
            t->size--;
            return true;
        }
        previous = current;
        current = current->next;
    }
    return false;
}