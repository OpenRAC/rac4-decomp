#include "common.h"

extern s32 func_0069D318(void *, void *);
extern s32 func_L00_0071B3C8();
extern void func_L00_0071BAF8();
extern s32 func_L00_007647B0(s32 identifier);
extern void *D_00220D14;
extern s32 D_004BB8F8[];

typedef struct { s32 a; s32 b; } Pair;
typedef struct { Pair p[10]; } Blob;

/* Flags the menu object, copies the 0x50-byte table at D_004BB8F8, hands its ten pairs to func_0069D318, then runs the +0x20 update of the children at +0xB0 and +0xB4. */
void func_L00_00729B98(u8 *arg0) {
    Blob loc;
    s32 *pa;
    s32 *pb;
    s32 va;
    s32 vb;
    u32 i;
    u8 *obj;

    if (*(u8 *)(arg0 + 0x269) == 0) {
        func_L00_007647B0(7);
    }
    *(u8 *)((u8 *)D_00220D14 + 0x114) = 1;
    func_L00_0071BAF8(arg0);
    loc = *(Blob *)D_004BB8F8;
    i = 0;
    pa = (s32 *)&loc;
    pb = (s32 *)&loc + 1;
    do {
        va = *pa;
        pa += 2;
        vb = *pb;
        pb += 2;
        i++;
        func_0069D318((void *)(*(s32 *)(arg0 + 0x240) | va), (void *)vb);
    } while (i < 10);
    obj = *(u8 **)(arg0 + 0xB0);
    ((void (*)(u8 *, s32, s32))*(void **)(*(u8 **)(obj + 0x58) + 0x20))(obj, 2, 0);
    obj = *(u8 **)(arg0 + 0xB4);
    ((void (*)(u8 *, s32, s32))*(void **)(*(u8 **)(obj + 0x58) + 0x20))(obj, 2, 0);
    func_L00_0071B3C8(arg0);
}
