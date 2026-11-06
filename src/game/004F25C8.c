#include "common.h"

/* Stores a word at an address passed as a 64-bit integer (the conversion back to a pointer is
 * the dsll32/dsra32 pair). */
void func_004F25C8(s32 value, s64 where) {
    *(s32 *)where = value;
}
