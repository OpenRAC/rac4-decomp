/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct __attribute__((packed)) Type1 {
    s8 f0[0x26];
} Type1;
extern s32 func_0011D5D8(const char *fmt, ...);
extern s32 func_01ED4460(void);
extern s32 func_01ED4760();
extern s32 func_01ED5DD0();
extern s32 func_01ED5A28();
extern s32 D_00169CD0[];
extern s32 D_00169CD4[];
extern s32 D_00169D50[];
extern s8 D_001984A0[];
extern s8 D_001984C0[];
extern s8 D_1B78E0[];
extern s32 D_1BC84C[];
extern s32 D_1BCA44[];

/* Clears two flag bytes, runs the handshake on the two globals, then copies the 0x26-byte block into D_1B78E0. */
s32 func_01ED6718(Type1 *arg0, s32 arg1, s32 arg2) {
    s32 temp_s0;

    arg0->f0[0x14] = 0;
    arg0->f0[0x25] = 0;
    temp_s0 = D_00169CD0[0];
    if (temp_s0 != 1) {
        return -0xF;
    }
    func_0011D5D8(D_001984A0);
    if (D_00169D50[0] == temp_s0 && func_01ED4460() != 0) {
        func_0011D5D8(D_001984C0);
        return -0xF;
    }
    if (D_00169CD4[0] == 0) {
        return -0x10;
    }
    D_1BCA44[0] = arg1;
    D_1BC84C[0] = arg2;
    func_0011D5D8(D_001984A0);
    if (D_00169D50[0] == 1) {
        *(Type1 *)D_1B78E0 = *arg0;
        if (func_01ED4760(func_01ED5A28, 0) == 0) {
            return (func_01ED5DD0(1, 0x15, 0x26, arg0) == 0) ? 0 : -5;
        }
        return -3;
    }
    return (func_01ED5DD0(1, 0x15, 0x26, arg0) == 0) ? 0 : -5;
}
