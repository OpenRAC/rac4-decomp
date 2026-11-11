/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    struct Type1 *next;
    struct Type1 *prev;
    s32 f8;
    s32 fC;
    s32 f10;
    u8 f14[0x3C];
    s32 f50;
    s32 f54;
    s32 f58;
    s32 f5C;
    s32 f60;
} Type1;

extern s32 func_00126A90(void);
extern s32 func_01E9BFE0(void *, s32, s32, s32);
extern void func_01E9C0B0(void *);
extern void *func_L00_005668D8(s32);
extern void func_L00_00566910(void *);
extern s32 func_L00_00566950(void);
extern void func_L00_005669C0(void);

extern s32 D_004A9B94[];
extern Type1 *D_004A9B98[];
extern Type1 *D_004A9B9C[];

Type1 *func_L00_005669E0(s32 arg0) {
    s32 id;
    Type1 *n;
    Type1 *next;
    s32 buf;
    u32 mask;

    id = func_00126A90();
    if (func_L00_00566950() < 0) {
        return 0;
    }
    for (n = D_004A9B98[0]; n != 0; n = n->next) {
        if (id == n->f8) {
            goto found;
        }
    }
    D_004A9B94[0]++;
    if (D_004A9B94[0] >= 0x100) {
        n = D_004A9B9C[0];
        next = n->next;
        if (n->prev != 0) {
            n->prev->next = next;
        } else {
            D_004A9B98[0] = next;
        }
        if (n->next != 0) {
            n->next->prev = n->prev;
        } else {
            D_004A9B9C[0] = n->prev;
        }
        func_01E9C0B0(n->f14);
        func_L00_00566910((void *)n->f50);
        func_L00_00566910(n);
        D_004A9B94[0]--;
    }
    n = func_L00_005668D8(0x64);
    if (n == 0) {
        goto found;
    }
    n->f8 = id;
    n->f58 = 0x800;
    n->f5C = 0x2000;
    n->f60 = 0x20;
    mask = 0xFFFFFFC0;
    buf = (s32)func_L00_005668D8(0x87F);
    n->f50 = buf;
    if (buf != 0) {
        n->f54 = (buf + 0x3F) & ~0x3F;
        if (func_01E9BFE0(n->f14, (n->f58 + 0x63) & mask, n->f5C, n->f60) >= 0) {
            goto insert;
        }
        func_L00_00566910((void *)n->f50);
    }
    func_L00_00566910(n);
    D_004A9B94[0]--;
    func_L00_005669C0();
    return 0;
insert:
    n->next = D_004A9B98[0];
    if (D_004A9B98[0] != 0) {
        D_004A9B98[0]->prev = n;
    } else {
        D_004A9B9C[0] = n;
    }
    D_004A9B98[0] = n;
    n->prev = 0;
found:
    if (arg0 == 0) {
        n->fC = 0;
    }
    return n;
}
