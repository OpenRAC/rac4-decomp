#include "common.h"

typedef struct Type2 {
    char _p0[0x10];
    s32 f10;
    char _p14[0x44 - 0x14];
    u16 f44;
} Type2;

typedef struct Type1 {
    char _p0[0x4];
    void (*f4)(void *);
    struct Type1 *f8;
    s32 fC;
    char _p10[0x24 - 0x10];
    Type2 *f24;
    char _p28[0x34 - 0x28];
    u16 f34;
    char _p36[0x98 - 0x36];
    s32 f98;
    char _p9C[0xB8 - 0x9C];
    struct Type1 *fB8;
} Type1;

extern void *func_L00_005DEBD0(s32, s32, s32);

/* Takes a node off the list in slot 0xF, runs its callback or copies the item's flags, and returns it. */
void *func_L01_00588BC0(s32 arg0) {
    Type1 *node;
    Type1 *obj;
    Type2 *item;
    s32 flags;
    s32 val;

    node = func_L00_005DEBD0(arg0, 0xF, 0x10);
    if (node == 0) {
        return 0;
    }
    obj = node->f8;
    if (obj == 0) {
        return 0;
    }
    node->f8 = obj->fB8;
    obj->fB8 = 0;
    if (node->f8 == 0) {
        node->fC = 0;
    }
    if (node->f4 != 0) {
        node->f4(obj);
    } else {
        item = obj->f24;
        flags = obj->f34 & 0xFFBE;
        obj->f34 = flags;
        flags = flags | (item->f44 & 0x1000);
        obj->f34 = flags;
        flags = flags & 0xFFFD;
        val = item->f10;
        obj->f34 = flags;
        obj->f98 = val;
    }
    return obj;
}
