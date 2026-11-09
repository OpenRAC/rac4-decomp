/* Not matching yet: BYTES 57/552 (tools/try_func.py func_0046CEA0 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
} Type1;

typedef struct {
    Type1 *f0;
    u32 f4;
} Type2;

extern void func_004537D0(s32 *, s32 *, s32);
extern s32 D_003D82F0[];
extern s32 D_003DA6B0[];
extern Type2 *D_0022144C;
extern Type1 *D_00221E20;
extern Type2 D_00265D60[];

void func_0046CEA0(void) {
    Type1 *head;
    Type2 *e;
    Type1 *pkt;
    u32 tag;
    u8 *info;
    u32 w;
    u32 n;
    u8 *base;
    s16 *src;
    u8 *dst;
    u32 stride;
    s32 tagv;
    u32 lo;
    s16 v;

    if (D_0022144C != D_00265D60) {
        head = D_00221E20++;
        e = D_00265D60;
        if (e < D_0022144C) {
            tagv = 0x20000000;
            do {
                pkt = e->f0;
                tag = e->f4;
                lo = tag & 0xF;
                ((s32 *)pkt)[0] = tagv;
                ((s32 *)pkt)[3] = 0x11000000;
                ((s32 *)pkt)[1] = (s32)D_00221E20;
                info = *(u8 **)((tag & ~0xF) + 0x24);
                w = info[0xB] & 0xF;
                n = info[0xB] >> 4;
                base = *(u8 **)(info + 0x20) - ((w * n) << 10) - 0x10;
                if (n != 0) {
                    src = (s16 *)base;
                    dst = base + ((lo << 10) + 0x10);
                    stride = w << 10;
                    do {
                        v = *src++;
                        func_004537D0((s32 *)D_00221E20, D_003D82F0, 0x70);
                        n--;
                        *(s16 *)((u8 *)D_00221E20 + 0x24) = v;
                        *(u8 **)((u8 *)D_00221E20 + 0x64) = dst;
                        dst += stride;
                        D_00221E20 += 7;
                    } while (n != 0);
                }
                ((s32 *)D_00221E20)[0] = 0x30000003;
                ((s32 *)D_00221E20)[1] = (s32)D_003DA6B0;
                ((s32 *)D_00221E20)[2] = 0;
                ((s32 *)D_00221E20)[3] = 0x50000003;
                D_00221E20++;
                ((s32 *)D_00221E20)[0] = tagv;
                ((s32 *)D_00221E20)[1] = (s32)(pkt + 1);
                ((s32 *)D_00221E20)[2] = 0;
                ((s32 *)D_00221E20)[3] = 0;
                D_00221E20++;
                e++;
            } while (e < D_0022144C);
        }
        ((s32 *)head)[0] = 0x20000000;
        ((s32 *)head)[1] = (s32)D_00221E20;
        ((s32 *)head)[2] = 0;
        ((s32 *)head)[3] = 0;
    }
}
