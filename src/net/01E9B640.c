/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 len; s32 blocks; char data[1]; } Pkt_8;
typedef struct { s32 f0; char _p4[0xC]; s32 size; } RInfo;
typedef struct {
    char _p0[4];
    s32 count;
    char _p8[0x14];
    char *cur;
    char _p20[8];
    char *base;
    char *limit;
    RInfo *info;
} Ring;
s32 func_01E9B640(Ring *r, char **p1, s32 *n1, char **p2, s32 *n2) {
    Pkt_8 *pk;
    s32 size;
    char *next;
    char *data;
    char *limit;
    s32 first;
    s32 rest;
    *p1 = 0;
    *n1 = 0;
    *p2 = 0;
    *n2 = 0;
    pk = (Pkt_8 *)r->cur;
    if ((char *)pk == r->base + r->info->size) {
        return 0;
    }
    data = pk->data;
    *p1 = data;
    size = pk->blocks << 6;
    next = (char *)pk + size;
    limit = r->limit;
    rest = size - (limit - (char *)pk);
    if (limit < next) {
        *n1 = first = limit - data;
        *p2 = r->base;
        *n2 = pk->len - first;
        r->cur = r->base + rest;
    } else {
        *n1 = pk->len;
        r->cur += size;
        if (limit == next) {
            r->cur = r->base;
        }
    }
    r->count++;
    return 0;
}
