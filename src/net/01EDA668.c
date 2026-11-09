/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct E_01EDA668 {
    u16 id;
    u8 pad2[0x8 - 0x2];
    s32 unk8;
    u8 padC[0x10 - 0xC];
    s32 unk10;
    s32 unk14;
} E_01EDA668;

typedef struct O_01EDA668 {
    s32 unk0;
    s16 unk4;
    s32 unk8;
    s32 unkC;
} O_01EDA668;

extern s32 func_01EA94D0(void *, s32);

O_01EDA668 *func_01EDA668(s32 arg0, E_01EDA668 **list, u32 size) {
    O_01EDA668 *p;
    u32 n;
    u16 count;
    u16 i;
    s32 mask;
    E_01EDA668 *e;

    mask = 0;
    n = size >> 2;
    count = n;
    if (list == NULL) {
        return NULL;
    }
    if (count == 0) {
        return NULL;
    }
    for (i = 0; i < count; i++) {
        e = list[i];
        if (e == NULL) {
            return NULL;
        }
        if (e->id != i) {
            return NULL;
        }
        if (e->unk14 == 0) {
            return NULL;
        }
        if (e->unk10 == 0) {
            return NULL;
        }
        if (e->unk8 == 0) {
            return NULL;
        }
        mask |= 1 << i;
    }
    func_01EA94D0(&p, 0x10);
    p->unk0 = arg0;
    p->unk8 = (s32)list;
    p->unk4 = n;
    p->unkC = mask;
    return p;
}
