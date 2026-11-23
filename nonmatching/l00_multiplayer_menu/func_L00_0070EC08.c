/* Not matching yet: BYTES 67/160 (tools/try_func.py func_L00_0070EC08 --diff). Not part of the build. */
#include "common.h"

typedef struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    char pad[0x20];
} Type1;

extern s32 D_002233A4;
extern Type1 D_003B1738[];
extern void func_L00_0070D1F0(void);

s32 func_L00_0070EC08(s32 arg0, Type1 *arg1) {
    Type1 *p;
    s32 result;
    s32 found;
    s32 cur;

    result = 1;
    if (arg0 == 2) {
        result = ~D_003B1738[0].f0;
        if (result) {
            cur = *(s32 *)((u8 *)D_002233A4 + 0x34);
            cur = *(s32 *)cur;
            found = 0;
            if (cur != -1) {
                found = cur == D_003B1738[0].f0;
            }
            if (found & 0xFF) {
                for (p = D_003B1738; (s32)p < (s32)(D_003B1738 + 5); p++) {
                    if (p->f0 == arg1->f8) {
                        p->f0 = -1;
                        func_L00_0070D1F0();
                        break;
                    }
                }
            }
        }
        result = 2;
    }
    return result;
}
