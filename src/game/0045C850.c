#include "common.h"
typedef struct { int value; int flag; } Entry;
typedef struct { int pad[2]; Entry entries[10]; int index; int pad5c; int count; int pad64[2]; unsigned char disabled; } Queue;
/* Add an entry unless the queue is full or disabled. */
int func_0045C850(Queue *q, int value) {
    int next;
    if (q->count == 10 || q->disabled) return 0;
    q->entries[q->index].value = value;
    q->entries[q->index].flag = value >= 100;
    next = q->index + 1;
    q->count = q->count + 1;
    q->index = next == 10 ? 0 : next;
    return 1;
}
