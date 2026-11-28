#ifndef RAC4_PAL_L00_HASH_TABLE_H
#define RAC4_PAL_L00_HASH_TABLE_H

#include "common.h"

typedef struct HashNode {
    union {
        s32 i;
        void *p;
    } key;
    struct HashNode *next;
    u64 hash;
} HashNode;

typedef s32 (*HashCompare)(s32, s32);
typedef u64 (*HashFunction)(s32);

typedef struct {
    HashNode **buckets;
    HashCompare compare;
    HashFunction hash;
    u32 slotCount;
    u32 size;
    u32 minIndex;
    u32 altSize;
    u64 upperLoad;
    u64 lowerLoad;
    u64 itemCount;
    u64 splits;
    u64 grows;
    u64 merges;
    u64 shrinks;
    u64 lookups;
    u64 compares;
    u64 inserted;
    u64 replaced;
    u64 removed;
    u64 removeMisses;
    u64 hits;
    u64 misses;
    u64 probes;
    u32 allocationFailures;
} HashTable;

extern void *func_L00_004FB1D8(s32 size);
extern void *func_L00_004FB200(void *buffer, u32 newSize, u32 oldSize);
extern void func_L00_004FB228(void *memory);
extern void func_L00_004F91D8(HashTable *table);
extern void func_L00_004F9350(HashTable *table);
extern HashNode **func_L00_004F9478(HashTable *table, s32 key, u64 *hash);

#endif
