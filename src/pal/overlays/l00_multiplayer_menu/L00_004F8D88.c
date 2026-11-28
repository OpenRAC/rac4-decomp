/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "pal/l00_hash_table.h"

extern s32 func_0011A8A0(s32, s32);
extern u64 func_L00_004F9580(s32);

HashTable *func_L00_004F8D88(HashFunction hash, HashCompare compare)
{
    HashTable *table;
    s32 i;

    table = func_L00_004FB1D8(sizeof(*table));
    if (table != NULL) {
        table->buckets = func_L00_004FB1D8(16 * sizeof(*table->buckets));
        if (table->buckets != NULL) {
            i = 0;
            do {
                table->buckets[i++] = NULL;
            } while (i < 16);

            table->compare = compare != NULL ? compare : func_0011A8A0;
            table->hash = hash != NULL ? hash : func_L00_004F9580;
            table->slotCount = 8;
            table->size = 16;
            table->altSize = 8;
            table->upperLoad = 512;
            table->lowerLoad = 256;
            table->minIndex = 0;
            table->itemCount = 0;
            table->splits = 0;
            table->grows = 0;
            table->merges = 0;
            table->shrinks = 0;
            table->lookups = 0;
            table->compares = 0;
            table->inserted = 0;
            table->replaced = 0;
            table->removed = 0;
            table->removeMisses = 0;
            table->hits = 0;
            table->misses = 0;
            table->probes = 0;
            table->allocationFailures = 0;
            return table;
        }
        func_L00_004FB228(table);
    }
    return NULL;
}
