/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_00504A58 (src/levels/39_multiplayer_menu/L39_00504A58.c, GPL-3.0), the same code in both games. */

typedef struct {
    u8 pad[0x1C];
    s32 f1C;
} Type1;
typedef struct {
    Type1 *f0;
    u8 pad4[0x74 - 0x4];
    s32 f74;
    void *f78;
    u8 pad7C[0x80 - 0x7C];
    s32 f80;
    u8 pad84[0x88 - 0x84];
    s64 f88;
} Type2;
extern void *func_0011A518(void *, s32, s32);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern void *func_L00_004FACD8(s32);
extern void func_L00_004FAD28(void *);
s32 func_L00_00540868(Type2 *arg0, Type1 *arg1) {
    if (arg0->f0 != 0) {
        if (arg0->f78 != 0) {
            func_0011A518(arg0->f78, 0, arg0->f74);
        }
        if (arg1 == 0 || arg0->f74 != arg1->f1C) {
            func_L00_004FAD28(arg0->f78);
            arg0->f78 = 0;
        }
    }
    if (arg1 != 0 && arg0->f78 == 0 && arg1->f1C > 0) {
        arg0->f78 = func_L00_004FACD8(arg1->f1C);
        if (arg0->f78 == 0) {
            func_L00_004F84C8(6, 0x6E, 0x21, 0, 0);
            return 0;
        }
    }
    if (arg1 != 0) {
        arg0->f74 = arg1->f1C;
        if (arg1->f1C > 0) {
            func_0011A518(arg0->f78, 0, arg1->f1C);
        }
        arg0->f0 = arg1;
    }
    arg0->f80 = 0;
    arg0->f88 = 0;
    return 1;
}
