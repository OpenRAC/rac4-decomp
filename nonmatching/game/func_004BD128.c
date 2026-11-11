/* Not matching yet: BYTES 19/732 (tools/try_func.py func_004BD128 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Rec24;

typedef struct {
    s32 unk0;
    s32 unk4;
} Obj;

typedef struct {
    s32 unk0;
    s32 unk4;
    Obj *unk8;
    s32 unkC;
    s32 unk10;
    s32 unk14;
} Slot;

typedef struct {
    u8 pad0[0x34];
    Slot *unk34;
    u8 pad38[0x18];
    s32 unk50;
    s32 unk54;
} Sub;

typedef struct {
    s32 unk0;
    s32 unk4;
    u8 pad8[0x4C0];
    Sub unk4C8;
    u8 pad[0x534 - 0x4C8 - 0x58];
} Player;

extern s32 func_0045E038(s32);
extern s32 func_0046B330(s32, s32);
extern s32 func_0046B3B8(s32, s32);
extern void func_004979A8(void *, s32, s32);
extern void func_00498C98(Rec24 *arg0);
extern s32 func_004A1A60(s32 *arg0, s32 arg1);
extern s32 func_004FBFD0(Rec24 *dst, s32 a, s32 b, s32 force);
extern void func_00504F68(s32, s32);
extern s32 func_00505238(s32, void *);
extern void func_00505328(s32, s32);
extern s32 func_005054F8(s32 id, s32 amount);
extern s32 func_00505B20(void);
extern void *func_0054A998(s32 arg0);
extern s32 func_0054AB08(s32 arg0, s32 arg1);
extern s32 func_0054AB78(s32);

extern s32 D_0021F920[];
extern s32 D_0021F930;
extern s32 D_00221820;
extern char D_0030A690[];
extern char D_0030A6C0[];
extern Player D_0030A6F0[];

void func_004BD128(void) {
    Rec24 buf[2];
    Player *p;
    Sub *sub;
    Slot *slot;
    Obj *obj;
    s32 ctx;
    s32 *ids;
    void *rec;
    s32 id;
    s32 a;
    s32 b;
    s32 n;
    s32 i;

    p = &D_0030A6F0[func_00505B20()];
    sub = &p->unk4C8;
    if (sub->unk50 > 0) {
        slot = NULL;
        if (sub->unk54 >= 0) {
            slot = &sub->unk34[sub->unk54];
        }
        obj = slot->unk8;
        if (obj != NULL) {
            ids = D_0021F920;
            i = 0;
            ctx = func_0054AB78(D_0021F930);
            rec = func_0054A998(func_0054AB08(ctx, obj->unk4));
            func_00505238(func_004A1A60(&D_00221820, 0x30), (void *)func_0045E038(*(s32 *)((u8 *)rec + 0xC)));
            func_00504F68(func_004A1A60(&D_00221820, 0x30), 1);
            a = func_0046B330(ctx, obj->unk4);
            b = func_0046B3B8(ctx, obj->unk4);
            func_004979A8(D_0030A690, a, 0);
            func_004979A8(D_0030A6C0, b, 0);
            func_00505238(func_004A1A60(&D_00221820, 0x28), D_0030A690);
            func_00505238(func_004A1A60(&D_00221820, 0x20), D_0030A6C0);
            id = func_004A1A60(&D_00221820, 0x31);
            func_00505238(id, (void *)func_0045E038(0x300F));
            id = func_004A1A60(&D_00221820, 0x32);
            func_00505238(id, (void *)func_0045E038(0x3010));
            func_00504F68(func_004A1A60(&D_00221820, 0x28), 1);
            func_00504F68(func_004A1A60(&D_00221820, 0x20), 1);
            n = func_004FBFD0(buf, ctx, obj->unk4, 0);
            for (; i < 2; i++) {
                func_00498C98(&buf[i]);
                func_00504F68(func_004A1A60(&D_00221820, *ids), i < n);
                func_005054F8(func_004A1A60(&D_00221820, *ids), buf[i].unk8);
                func_00505328(func_004A1A60(&D_00221820, *ids++), buf[i].unkC);
            }
        }
    }
    p->unk4 = (p->unk4 | 4) & ~1;
}
