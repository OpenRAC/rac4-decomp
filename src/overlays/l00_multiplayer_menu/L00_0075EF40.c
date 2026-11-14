#include "common.h"

typedef struct { u8 pad[0x104]; u8 f104[10]; u8 f10E[10]; u8 pad2[0x0]; s32 f118; } Type2;
typedef struct { u8 pad[0x10]; s32 f10; u8 pad2[0x23D]; u8 f251; u8 pad3[0x8A]; s32 f2DC; } Type3;
extern s32 func_L00_0071B550(s32, s32);
extern void func_L00_0075F078();
extern Type2 *D_0021DFE8;
extern Type2 *D_00220D14;
extern Type3 D_172160[];

/* Flag the menu object when the local player's slot is in a blocking state. */
s32 func_L00_0075EF40(s32 arg0, s32 arg1) {
    Type2 *p;
    s32 i;
    s32 idx;

    func_L00_0075F078();
    if (D_0021DFE8 != 0) {
        idx = -1;
        for (i = 0; i < 10; i++) {
            if (D_0021DFE8->f104[i] == D_172160[0].f10) {
                idx = i;
                break;
            }
        }
        if (idx < 0) {
            return 0;
        }
        p = D_0021DFE8;
        if ((p != 0 && p->f10E[idx] == 5) || D_172160[0].f251 != 0 || D_172160[0].f2DC != 0
            || (p != 0 && p->f10E[0] >= 7)) {
            D_00220D14->f118 = 0x2A;
            return 1;
        }
    }
    return func_L00_0071B550(arg0, arg1) != 0;
}
