#include "common.h"
typedef struct {
    int id, value;
} Entry;
typedef struct {
    char pad[8];
    Entry entries[10];
    int write, read;
} Queue;
extern unsigned int D_00171C08[];
void func_0045C8E8(Queue *q)
{
    int i = q->read;
    while (i != q->write) {
        int id = q->entries[i].id;
        if (id >= 0)
            D_00171C08[(unsigned int)id >> 5] |= 1u << (id & 31);
        i = (i + 1) == 10 ? 0 : i + 1;
    }
}
