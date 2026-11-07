/* Not matching yet: BYTES 30/620 (tools/try_func.py func_004BDDF8 --diff). Not part of the build. */
#include "common.h"

typedef struct {
    s32 (*fn0)(s32, s32, s32);
    s32 pad4;
    s32 (*fn8)(void);
} Type1;

typedef struct {
    u8 pad0[0x18];
    void (*fn18)(void);
} Type2;

typedef struct {
    u8 pad0[2];
    u8 unk2;
    u8 pad3;
    s32 unk4;
    s32 unk8;
} Type3;

typedef struct {
    s32 pad0;
    s32 pad4;
    Type3 *unk8;
    u8 padC[0xC];
} Type4;

extern void func_0045CA60(s32 arg0, s32 arg1, s32 arg2);
extern void func_0046A290(s32 arg0);
extern void *func_0046D428(s32 arg0, s32 arg1, s32 arg2);
extern void func_00498CF8(void);
extern void func_004BDD90(void);
extern s32 func_004BEEA0(s32 arg0);
extern s32 D_0021DE10[];
extern s32 D_0021EDD4[];
extern s32 D_0021EDD8[];
extern char D_30B358[];

static inline void func_004BDDF8_a(s32 mode, s32 arg) {
    Type1 *p;

    p = func_0046D428(0x208A, 0, 0x14);
    if (p == NULL) {
        p = func_0046D428(0x2766, 0, 0x14);
    }
    if (p != NULL && p->fn0 != NULL && p->fn8 != NULL && p->fn8() != 0) {
        p->fn0(mode, arg, 1);
    } else {
        func_0045CA60(mode, 1, arg);
    }
}

static inline void func_004BDDF8_b(s32 arg) {
    Type2 *p;

    p = func_0046D428(0x20A3, 0x10, 0x1C);
    if (p != NULL && p->fn18 != NULL) {
        p->fn18();
    }
    func_0046A290(arg);
}

void func_004BDDF8(void) {
    u8 *rec;
    s32 base;
    s32 idx;
    Type4 *ent;
    Type3 *e;
    s32 mode;
    s32 sel;
    s32 val;

    base = (s32)D_30B358;
    rec = (u8 *)(base + 0x1EC);
    idx = *(s32 *)(rec + 0x54);
    if (idx < 0) {
        ent = NULL;
    } else {
        ent = (Type4 *)(*(s32 *)(rec + 0x34)) + idx;
    }
    mode = 1;
    e = ent->unk8;
    if (D_0021EDD4[0] == 0) {
        if (D_0021EDD8[0] == 1) {
            mode = 0x15;
        }
    }
    sel = D_0021DE10[0] % 20;
    if (e->unk8 == 0) {
        mode = e->unk4;
    }
    if (e->unk8 != 0) {
        val = func_004BEEA0(e->unk4);
    } else {
        val = 0;
    }
    if (e->unk2 != 0) {
        if (e->unk8 == 0) {
            func_004BDDF8_a(mode, val);
        } else if (sel != 1) {
            func_0045CA60(mode, 1, -1);
        } else {
            goto do_b;
        }
done:
        func_004BDD90();
        return;
    }
    if (sel == 1) {
        func_00498CF8();
do_b:
        func_004BDDF8_b(val);
        goto done;
    }
    func_00498CF8();
    func_004BDDF8_a(mode, val);
    func_004BDD90();
}
