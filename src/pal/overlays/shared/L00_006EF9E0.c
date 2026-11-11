#include "common.h"

typedef struct S_6EF9E0 S_6EF9E0;
struct S_6EF9E0 {
    u8 pad[88];
    S_6EF9E0 *next;
};
extern S_6EF9E0 D_003533A0[];
/* Retail reaches it through $gp ($gp = 0x2259FF). */
S_6EF9E0 *D_00220758 = 0;
extern void func_L00_006EFE80(S_6EF9E0 *);

/* PAL: from rac3-decomp's func_L39_00662528 */
void func_L00_006EF9E0(void) {
    s32 i;
    for (i = 0; i < 256; i++) {
        func_L00_006EFE80(&D_003533A0[i]);
    }
    for (i = 254; i >= 0; i--) {
        D_003533A0[i].next = &D_003533A0[i + 1];
    }
    D_00220758 = D_003533A0;
}
