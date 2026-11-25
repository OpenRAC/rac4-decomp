#include "common.h"

typedef int s128 __attribute__((mode(TI)));
extern s32 func_L00_005F1208(s128, s32);
extern void *func_L00_005F2FB8(void);
extern void *D_363038[];

s32 func_L05_004DBBB0(void *arg0) {
    u8 *data = *(u8 **)((u8 *)arg0 + 0xAC);
    s32 id;
    s32 i;
    void **p;
    void *obj;
    s32 j;
    void *v0;
    u8 *base;

    if (*(u8 *)(data + 0x54A) != 0) { id = *(s32 *)(data + 0x534); } else { id = *(s32 *)(data + 0x540); }
    if (id == -1) {
        return 1;
    }

    i = 0;
    p = D_363038;
    obj = *p;
    do {
        if (obj != 0 && func_L00_005F1208(*(s128 *)((u8 *)obj + 0xA0), id) == 0) {
            return 0;
        }
        p++;
        i++;
        obj = *p;
    } while (i < 10);

    j = 0;
    do {
        base = func_L00_005F2FB8();
        base += j * 4;
        v0 = *(void **)(base + 0x1D0);
        if (v0 != 0 && func_L00_005F1208(*(s128 *)((u8 *)v0 + 0x10), id) == 0) {
            return 0;
        }
        j++;
    } while (j < 4);

    return 1;
}
