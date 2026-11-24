#include "common.h"

typedef struct Context {
    u8 pad0[0x64];
    s32 x64[0x29];
} Context;

typedef struct Heap {
    u8 pad0[0x14];
    u8 *x14;
    u8 *x18;
    u8 pad1C[0x4];
    u8 *x20;
} Heap;

extern Heap D_003B16D0;
extern u8 D_003B1C60[];
extern u8 D_004B9B10[];
extern u8 D_004C2060[];
extern void *D_0021DFF4;
extern void *D_0021DFF8;
extern void *D_0021E000;

Context *D_00220DD4 = 0;
u8 *D_00220DD8 = 0;
s32 D_00220DDC = 0;
void *D_0021DFFC = 0;
void *D_0021E004 = 0;

void *func_0015DB90(s32, void *);
Context *func_L00_0071DDD0(void *);
s32 func_L00_0071CAB0(u8 *, s32);
void *func_01EED5A8(void *);
void *func_01EED5EC(void *);
void *func_L00_007825A8(void *);
void *func_L00_007832A0(void *);
void *func_L00_00783360(void *);
void func_L00_0070CF40(void);
void func_L00_0070E318(void);
void func_L00_007110B0(void);
void func_L00_0073F9A8(void);
void func_L00_00756560(void);
void func_L00_00761BD8(void);

// Sets up the level's memory: a 0x130-byte context with 41 entries, then
// several objects carved one after another from a fixed buffer.
// func_01EED5A8 and func_01EED5EC are declared here as returning a pointer
// (their code leaves a value in v0); only the register choice depends on it.
void func_L00_0071C118(u8 *base, s32 size) {
    s32 i;
    u8 *b;
    u8 *p;
    u8 *q;

    D_003B16D0.x20 = base + size;
    D_00220DDC = size;
    D_003B16D0.x14 = base;
    D_00220DD8 = base;
    D_00220DD4 = func_L00_0071DDD0(func_0015DB90(0x130, base));
    D_00220DD8 += 0x130;
    D_00220DDC -= 0x130;
    for (i = 0; i < 0x29; i++) {
        D_00220DD4->x64[i] = func_L00_0071CAB0((u8 *)D_00220DD4, i);
    }
    b = D_003B1C60;
    p = func_0015DB90(4, b);
    b += 4;
    func_01EED5A8(p);
    D_0021DFF4 = p;
    *(u8 **)p = D_004B9B10;
    D_0021DFF8 = func_L00_007825A8(func_0015DB90(8, b));
    b += 8;
    q = func_0015DB90(0xE4, b);
    b += 0xE4;
    func_01EED5EC(q);
    *(u8 **)(q + 0xD8) = D_004C2060;
    D_0021DFFC = q;
    D_0021E000 = func_L00_007832A0(func_0015DB90(0x10420, b));
    D_0021E004 = func_L00_00783360(func_0015DB90(0x404, b + 0x10420));
    func_L00_0070CF40();
    func_L00_0070E318();
    func_L00_007110B0();
    func_L00_0073F9A8();
    func_L00_00756560();
    func_L00_00761BD8();
    D_003B16D0.x18 = D_00220DD8;
}
