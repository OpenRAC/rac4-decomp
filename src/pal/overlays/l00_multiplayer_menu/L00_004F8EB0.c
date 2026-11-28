/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "pal/l00_hash_table.h"

extern u64 func_0012FEB0(u64 dividend, u64 divisor);

void func_L00_004F8EB0(HashTable *table)
{
    u32 i;

    for (i = 0; i < table->slotCount; i++) {
        HashNode *node = table->buckets[i];

        while (node != NULL) {
            HashNode *next = node->next;
            func_L00_004FB228(node);
            node = next;
        }
    }
    func_L00_004FB228(table->buckets);
    func_L00_004FB228(table);
}

void *func_L00_004F8F38(HashTable *table, void *key)
{
    HashNode **link;
    HashNode *node;
    u64 hash;
    void *previous;

    table->allocationFailures = 0;
    if (func_0012FEB0(table->itemCount << 8, table->slotCount) >= table->upperLoad) {
        func_L00_004F91D8(table);
    }

    link = func_L00_004F9478(table, (s32)key, &hash);
    node = *link;
    if (node == NULL) {
        HashNode *newNode = func_L00_004FB1D8(sizeof(*newNode));

        if (newNode == NULL) {
            table->allocationFailures++;
            return NULL;
        }
        previous = NULL;
        newNode->key.p = key;
        newNode->next = NULL;
        newNode->hash = hash;
        *link = newNode;
        table->inserted++;
        table->itemCount++;
    } else {
        previous = node->key.p;
        node->key.p = key;
        table->replaced++;
    }
    return previous;
}

void *func_L00_004F9028(HashTable *table, void *key)
{
    HashNode **link;
    HashNode *node;
    u64 hash;
    void *removedKey;

    table->allocationFailures = 0;
    link = func_L00_004F9478(table, (s32)key, &hash);
    node = *link;
    if (node == NULL) {
        table->removeMisses++;
        return NULL;
    }

    *link = node->next;
    removedKey = node->key.p;
    func_L00_004FB228(node);
    table->removed++;
    table->itemCount--;
    if (table->slotCount > 16 &&
        func_0012FEB0(table->itemCount << 8, table->slotCount) <= table->lowerLoad) {
        func_L00_004F9350(table);
    }
    return removedKey;
}
