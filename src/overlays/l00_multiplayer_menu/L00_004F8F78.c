/* cflags: @ee29 */
#include "common.h"

extern u64 func_00130480(u64, u64);

typedef struct HashNode {
    union {
        s32 i;
        void *p;
    } key;
    struct HashNode *next;
    u64 hash;
} HashNode;

typedef struct {
    HashNode **buckets;
    s32 (*compare)(s32, s32);
    u64 (*hash)(s32);
    u8 padC[0x10 - 0xC];
    u32 size;
    u32 minIndex;
    u32 altSize;
    u8 pad1C[0x58 - 0x1C];
    u64 lookups;
    u64 compares;
    u8 pad68[0x98 - 0x68];
    u64 probes;
} HashTable;

HashNode **func_L00_004F8F78(HashTable *t, s32 key, u64 *outHash) {
    u64 h = t->hash(key);
    u64 idx;
    s32 (*compare)(s32, s32);
    HashNode **pp;
    HashNode *n;

    t->lookups++;
    *outHash = h;
    idx = func_00130480(h, t->altSize);
    if (idx < t->minIndex) {
        idx = func_00130480(h, t->size);
    }
    compare = t->compare;
    pp = &t->buckets[(s32)idx];
    n = *pp;
    while (n != NULL) {
        t->probes++;
        if (n->hash == h) {
            t->compares++;
            if (compare(n->key.i, key) == 0) {
                break;
            }
        }
        pp = &n->next;
        n = n->next;
    }
    return pp;
}
