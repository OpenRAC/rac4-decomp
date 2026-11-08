#include "common.h"

typedef struct {
    s32 offset;
    s32 data;
    u16 size;
    s16 kind;
    s16 arg1;
    s16 arg0;
} Entry_4A0270;
typedef struct {
    s32 count;
    Entry_4A0270 entries[1];
} Table_4A0270;
extern u8 *func_L00_00665120(s32 a, s32 b);
extern void func_005BCBF0(void *dst, void *src, s32 size);

/* from rac3-decomp's func_L01_004A3AD0, constants adapted */
void func_L00_00665160(Table_4A0270 *table) {
    s32 i;
    for (i = 0; i < table->count; i++) {
        Entry_4A0270 *e = &table->entries[i];
        u8 *obj = func_L00_00665120(e->arg0, e->arg1);
        if (obj != 0) {
            u8 *dst;
            if (e->kind == 1) {
                dst = (u8 *)e->offset + (s32)obj;
            } else {
                dst = (u8 *)e->offset + *(s32 *)(obj + 172);
            }
            func_005BCBF0(dst, &e->data, e->size);
        }
    }
}
