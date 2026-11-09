/* Not matching yet: BYTES 23/464 (tools/try_func.py func_L00_00528178 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type3 {
    u8 f0;
    u8 pad1[3];
    s32 f4;
    u8 pad8[8];
    char *f10;
} Type3;

typedef struct Type1 {
    u8 pad0[0x54];
    u8 *f54;
    u8 pad58[0x68 - 0x58];
    u32 f68;
    s32 f6C;
    u8 pad70[4];
    u32 f74;
    s32 f78;
} Type1;

extern char D_004A19C0[];
extern char D_004A19F0[];

extern void func_L00_00519490(s32 arg0, s32 arg1);
extern void func_L00_00519578(s32 arg0, void *arg1, u32 arg2);
extern void func_L00_005195A8(s32 arg0, void *arg1, u32 *arg2);

u32 func_L00_00528178(Type1 *arg0, u8 *arg1, s32 arg2) {
    u8 c;
    u32 n;
    u8 *ctr;
    Type3 *rec;
    u8 *key;
    s32 h;
    u32 width;
    s32 i;

    if (arg2 != 0) {
        n = arg0->f74;
        ctr = arg0->f54 + 0x28;
        rec = (Type3 *)(arg0->f54 + 0xCC);
        key = arg0->f54 + 0x30;
        h = arg0->f78;
    } else {
        n = arg0->f68;
        ctr = arg0->f54 + 0xC;
        rec = (Type3 *)(arg0->f54 + 0xB4);
        h = arg0->f6C;
        key = arg0->f54 + 0x14;
    }
    width = (0x30 / n) * n;
    func_L00_00519490(h, 0);
    func_L00_00519578(h, key, n);
    func_L00_00519578(h, D_004A19C0, width);
    func_L00_00519578(h, ctr, 8);
    c = rec->f0;
    func_L00_00519578(h, &c, 1);
    arg1[0] = (u32)rec->f4 >> 8;
    arg1[1] = rec->f4;
    func_L00_00519578(h, arg1, 2);
    func_L00_00519578(h, rec->f10, rec->f4);
    func_L00_005195A8(h, arg1, NULL);
    func_L00_00519490(h, 0);
    func_L00_00519578(h, key, n);
    func_L00_00519578(h, D_004A19F0, width);
    func_L00_00519578(h, arg1, n);
    func_L00_005195A8(h, arg1, &n);
    for (i = 7; i >= 0; i--) {
        if (++ctr[i] != 0) {
            break;
        }
    }
    return n;
}
