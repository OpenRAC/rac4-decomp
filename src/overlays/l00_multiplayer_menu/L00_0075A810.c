#include "common.h"

typedef struct Type3 Type3;
typedef struct { char pad[0x20]; void (*f20)(Type3 *, s32, s32); char pad2[0x20]; s32 (*f44)(Type3 *); } Type4;
struct Type3 { char pad[0x58]; Type4 *f58; };
typedef struct { char pad[0x10E]; u8 f10E; } Type2;
typedef struct {
    char pad[0xB0];
    Type3 *fB0[53];
    Type3 *f184;
    Type3 *f188;
    char pad2[4];
    Type3 *f190;
    char pad3[0x9C];
    s32 f230;
} Type1;
extern Type2 *D_0021DFE8;
extern void func_L00_0071BA48(void *, u32);

/* Selects a menu entry or resets three widgets when the session is past state 6. */
void func_L00_0075A810(Type1 *arg0) {
    Type3 *o;
    s32 i;

    if (D_0021DFE8 != NULL && D_0021DFE8->f10E >= 7) {
        o = arg0->f184;
        o->f58->f20(o, 1, 0);
        o = arg0->f188;
        o->f58->f20(o, 1, 0);
        o = arg0->f190;
        o->f58->f20(o, 1, 0);
        func_L00_0071BA48(arg0, -1);
        return;
    }
    i = arg0->f230;
    if (i != -1) {
        o = arg0->fB0[i];
        func_L00_0071BA48(arg0, o->f58->f44(o));
        return;
    }
    func_L00_0071BA48(arg0, -1);
}
