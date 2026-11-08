#include "common.h"

typedef struct S_6EBE20 S_6EBE20;
struct S_6EBE20 {
    u8 pad[88];
    S_6EBE20 *next;
};
extern S_6EBE20 D_003533A0[];
S_6EBE20 *D_002206A8 = 0;
extern void func_L00_006EC2C0(S_6EBE20 *);

/* from rac3-decomp's func_L39_00662528 */
void func_L00_006EBE20(void) {
    s32 i;
    for (i = 0; i < 256; i++) {
        func_L00_006EC2C0(&D_003533A0[i]);
    }
    for (i = 254; i >= 0; i--) {
        D_003533A0[i].next = &D_003533A0[i + 1];
    }
    D_002206A8 = D_003533A0;
}
