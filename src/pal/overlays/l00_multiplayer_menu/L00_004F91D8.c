/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "pal/l00_hash_table.h"


extern u64 func_00130480(u64 value, u64 modulus);

/* Split the next bucket, then double the bucket allocation at the end of a round. */
void func_L00_004F91D8(HashTable *t) {
    u32 split = t->minIndex;
    HashNode **newBucket = &t->buckets[split + t->altSize];
    HashNode **oldBucket;
    HashNode *node;
    u64 size;

    t->slotCount++;
    t->splits++;
    t->minIndex = split + 1;
    oldBucket = &t->buckets[split];
    *newBucket = NULL;

    size = t->size;
    node = *oldBucket;
    if (node != NULL) {
        do {
            if (func_00130480(node->hash, size) != split) {
                *oldBucket = node->next;
                node->next = *newBucket;
                *newBucket = node;
            } else {
                oldBucket = &node->next;
            }
            node = *oldBucket;
        } while (node != NULL);
    }

    if (t->minIndex >= t->altSize) {
        u32 newSize = t->size * 2;
        HashNode **buckets = func_L00_004FB200(t->buckets, newSize * sizeof(*buckets), t->size * sizeof(*buckets));
        if (buckets == NULL) {
            t->minIndex = 0;
            t->allocationFailures++;
        } else {
            u32 i = t->size;
            if (i < newSize) {
                HashNode **p = (HashNode **)(i * sizeof(*p) + (u32)buckets);
                do {
                    *p = NULL;
                    i++;
                    p++;
                } while (i < newSize);
            }
            t->buckets = buckets;
            t->altSize = t->size;
            t->size = newSize;
            t->grows++;
            t->minIndex = 0;
        }
    }
}

/* Merge the last active bucket into its partner, halving storage between rounds. */
void func_L00_004F9350(HashTable *t) {
    u32 lastIndex = t->minIndex + t->altSize;
    HashNode **buckets = t->buckets;
    HashNode *nodes = buckets[lastIndex - 1];
    HashNode *node;

    buckets[lastIndex - 1] = NULL;
    if (t->minIndex == 0) {
        HashNode **resized = func_L00_004FB200(t->buckets, (t->size >> 1) * sizeof(*buckets), t->size * sizeof(*buckets));
        if (resized == NULL) {
            t->allocationFailures++;
            return;
        }
        t->shrinks++;
        t->size >>= 1;
        t->minIndex = (t->altSize >> 1) - 1;
        t->buckets = resized;
        t->altSize >>= 1;
    } else {
        t->minIndex--;
    }

    t->slotCount--;
    t->merges++;
    node = t->buckets[t->minIndex];
    if (node == NULL) {
        t->buckets[t->minIndex] = nodes;
    } else {
        while (node->next != NULL) {
            node = node->next;
        }
        node->next = nodes;
    }
}
