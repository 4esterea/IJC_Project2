// pr_htab.h
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#ifndef __PR_HTAB_H__
#define __PR_HTAB_H__

#include "htab.h"

struct htab_item
{
    htab_pair_t pair;
    struct htab_item *next;
};

struct htab{
    unsigned int size;
    unsigned int arr_size; 
    struct htab_item **arr_ptr;
};

#endif