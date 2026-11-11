#include "common.h"

typedef struct Type1 {
    char pad0[0x2F14];
    s32 f2F14;
    char pad2F18[0x10];
    s32 *f2F28;
} Type1;

typedef struct Type0 {
    char pad0[0x194];
    u8 f194;
    u8 f195;
} Type0;

extern void func_0011A518(void *, s32, s32);
extern Type0 D_00172160;
extern Type1 *D_003367B8[];

// Clear the 0x195 flag when two entries share a key but differ in group, or fewer than two entries/groups exist; set the 0x194 flag.
void func_00546A68(void) {
    u8 seen[10];
    s32 count = 0;
    s32 groups = 0;
    s32 i;
    s32 j;

    func_0011A518(seen, 0, 10);
    D_00172160.f195 = 1;
    for (i = 0; i < 10; i++) {
        if (D_003367B8[i] != 0) {
            Type1 *e;
            s32 key;
            s32 grp;
            if (seen[D_003367B8[i]->f2F14] == 0) {
                seen[D_003367B8[i]->f2F14] = 1;
                groups++;
            }
            e = D_003367B8[i];
            count++;
            key = *e->f2F28;
            grp = e->f2F14;
            for (j = i + 1; j < 10; j++) {
                if (D_003367B8[j] != 0) {
                    if (*D_003367B8[j]->f2F28 == key) {
                        if (D_003367B8[j]->f2F14 != grp) {
                            D_00172160.f195 = 0;
                            break;
                        }
                    }
                }
            }
        }
    }
    if (D_00172160.f195 == 0 || count < 2 || groups < 2) {
        D_00172160.f195 = 0;
    }
    D_00172160.f194 = 1;
}
