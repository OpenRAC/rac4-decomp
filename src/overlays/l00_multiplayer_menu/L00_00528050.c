/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type2 {
    u8 pad0[0x10];
    s32 f10;
    char f14[1];
} Type2;

typedef struct Type1 {
    u8 pad0[0xB0];
    Type2 *fB0;
    u8 padB4[0x128 - 0xB4];
    s32 f128;
} Type1;

extern s32 func_0051A6E8(s32 arg0);
extern s32 func_00540E60(s32 arg0);
extern void func_L00_00519490(s32 arg0, s32 arg1);
extern void func_L00_00519578(s32 arg0, char *arg1, s32 arg2);
extern void func_L00_005195A8(s32 arg0, char *arg1, s32 *arg2);
extern s32 func_L00_00540F30(s32 arg0);
extern char D_004A19C0[];
extern char D_004A19F0[];

s32 func_L00_00528050(Type1 *arg0, s32 arg1, char *arg2, s32 arg3, char *arg4) {
    char buf[0x20];
    s32 sp20;
    s32 sp24;
    s32 n;
    s32 width;

    if (func_L00_00540F30(arg0->f128) == 0) {
        return 0;
    }
    n = func_0051A6E8(arg0->f128);
    width = (0x30 / n) * n;
    if (arg2 != NULL) {
        func_L00_00519578(arg0->f128, arg2, arg3);
    }
    func_L00_00519578(arg0->f128, arg0->fB0->f14, arg0->fB0->f10);
    func_L00_00519578(arg0->f128, D_004A19C0, width);
    func_L00_005195A8(arg0->f128, buf, &sp20);
    func_L00_00519490(arg0->f128, func_00540E60(arg0->f128));
    func_L00_00519578(arg0->f128, arg0->fB0->f14, arg0->fB0->f10);
    func_L00_00519578(arg0->f128, D_004A19F0, width);
    func_L00_00519578(arg0->f128, buf, sp20);
    func_L00_005195A8(arg0->f128, arg4, &sp24);
    return sp24;
}
