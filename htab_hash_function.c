// htab_hash_function.c
// Řešení IJC-DU2, příklad 2, 17.4.2023
// Autor: Zhdanovich Iaroslav (xzhdan00), FIT
// Přeloženo: gcc 9.4.0

#include "htab.h"
#include "pr_htab.h"
#include <stdint.h>

size_t htab_hash_function(const char *str) {
  uint32_t h=0;     // musí mít 32 bitů
  const unsigned char *p;
  for(p=(const unsigned char*)str; *p!='\0'; p++)
    h = 65599*h + *p;
  return h;
}