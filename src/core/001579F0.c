#include "common.h"

typedef struct {
    u64 f0 : 1;
    u64 f1 : 1;
    u64 f2 : 1;
    u64 f3 : 11;
    u64 f4 : 11;
    u64 f5 : 3;
    u64 pad : 4;
    u64 high;
} Hdr;

extern u8 D_00171D38[];
extern u8 D_0021DC88[];
extern u32 D_0021DE6C;
extern u16 D_21DAA8;
extern u16 D_21DAAC;
extern char *func_0011A9EC(char *, char *);
extern s32 func_0011D920(s8 *, s8 *, ...);

void func_001579F0(s32 arg0) {
    Hdr h;
    char buf[16];
    u8 *hp;
    u32 i;

    h.f1 = D_0021DE6C;
    h.f0 = D_00171D38[0xB3];
    h.f2 = *(u32 *)(D_00171D38 + 8);
    h.f3 = *(u32 *)(D_00171D38 + 0xC);
    h.f4 = *(u32 *)(D_00171D38 + 0x10);
    h.f5 = D_00171D38[0xBD];
    ((u16 *)((u8 *)&h))[2] = D_21DAA8;
    ((u16 *)((u8 *)&h))[3] = D_21DAAC;
    hp = (u8 *)&h;

    for (i = 0; i < 8; i++) {
        func_0011D920((s8 *)buf, (s8 *)D_0021DC88, hp[i]);
        func_0011A9EC((char *)arg0, buf);
        arg0 += 2;
    }
}
