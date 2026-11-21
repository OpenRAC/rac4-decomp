/* cflags: @ee296 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

extern s32 func_0011D5D8(const char *fmt, ...);
extern int func_00126BA0();
void func_00154070(s32);
void func_00154178(void);
void func_00155070(void);
void func_00155260(void *, s32, s32);
extern u8 D_0016F900[];
extern u8 D_001A44F0[];
extern u8 D_001A4568[];
extern u8 D_001A45B0[];
extern void func_00155038(void);

typedef struct {
    u8 pad0[0x2C];
    s32 f2C;
    u8 pad30[4];
    s32 f34;
    s32 f38;
    s32 f3C;
    s32 f40;
    s32 f44;
    u8 pad48[0x18];
    s32 f60;
    u8 pad64[0xC];
    s64 f70;
    s32 f78;
    void *f7C;
    void *f80;
    s32 f84;
} Type1;
extern Type1 D_1BCC28;

/* starts the D_1BCC28 service: clamps the two limits to 4, sets up its fields and handler, then marks it running */
s32 func_00154930(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    s32 loc[8];
    s32 v;

    if (D_1BCC28.f34 != 0) {
        func_0011D5D8((const char *)D_001A4568);
        return 0x80000000;
    }
    func_0011D5D8((const char *)D_001A45B0, 1, 8, 8, arg2);
    if (arg1 >= 5) {
        arg1 = 4;
    }
    if (arg0 >= 5) {
        arg0 = 4;
    }
    D_1BCC28.f40 = arg0;
    D_1BCC28.f44 = arg1;
    D_1BCC28.f70 = 0x64;
    D_1BCC28.f78 = 0x1F4;
    D_1BCC28.f60 = 1;
    if (D_0016F900 != NULL) {
        D_1BCC28.f84 = 0x4B;
        D_1BCC28.f7C = D_0016F900;
        func_00155260(D_0016F900, 0, 0x4A);
    }
    D_1BCC28.f38 = 0;
    D_1BCC28.f3C = 0;
    loc[2] = 1;
    loc[1] = 1;
    v = func_00126BA0(loc);
    D_1BCC28.f2C = v;
    if (v == -1) {
        func_0011D5D8((const char *)D_001A44F0);
        for (;;) {
        }
    }
    func_00154178();
    if (arg3 == NULL) {
        func_00155070();
        D_1BCC28.f80 = (void *)func_00155038;
    } else {
        D_1BCC28.f80 = arg3;
    }
    func_00154070(arg2);
    D_1BCC28.f34 = 1;
    return 0;
}
