#include "common.h"
typedef struct {
    int a, b, c;
} Record;
typedef struct {
    int f0, read, count, fC;
    Record records[64];
} Queue;
extern int func_00504EB0(Queue *);
int func_00504F10(Queue *q, Record *out)
{
    if (!q->count)
        return 0;
    *out = q->records[q->read];
    func_00504EB0(q);
    return 1;
}
