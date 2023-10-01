// htab_lookup_add.c
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include <stdlib.h>
#include <stdio.h>
#include "htab.h"
#include "pr_htab.h"

htab_pair_t * htab_lookup_add(htab_t * t, htab_key_t key){
    htab_pair_t *found = htab_find(t, key);
    if (found) return found;
    size_t hashKey = htab_hash_function(key) % t->arr_size;
    struct htab_item *item_to_add = malloc(sizeof(struct htab_item));
    if (!(item_to_add)) return NULL;
    char *content = malloc(strlen(key) + 1);
    if (!(content)) {
        free(item_to_add); 
        return NULL;
    }
    strcpy(content, key);
    content[strlen(key)] = '\0';
    item_to_add->pair.key = content;
    item_to_add->pair.value = 0;
    item_to_add->next = NULL;
    t->size++; 
    struct htab_item *temp= t->arr_ptr[hashKey];
    t->arr_ptr[hashKey] = item_to_add;
    item_to_add->next = temp;
    return &(item_to_add->pair);
}