#include "common.h"

typedef struct Stat {
    u8 pad0[0x30];
    s32 x30;
    u8 pad34[0xC];
} Stat;

extern s32 D_0021EE54;
extern u8 D_00172444[];
extern u8 D_0021EF80[];

void func_00449B28(s32, s32);
void func_00163990(void);
void func_004E5B78(s32);
void func_00163550(s32);
void func_01E9A858(Stat *, u8 *, s32);
void func_01E9A7C8(void);
void func_0015A080(void);
void func_00127A08(s32);
void func_01E9A590(s32);
void func_01E9A0F0(void);
void func_00131A08(s32, s32);
void func_00139940(s32);
void func_00127600(s32);
void func_0013B810(s32, s32);
void func_0013B088(s32);
void func_0013B460(void);
void func_0013AFF8(void);
void func_0013A7A0(s32, s32, s32);
s32 func_0013A0F0(void);
void func_00159FA8(void);
s32 func_001376B0(s32);
void func_0045FC78(u8 *);
void func_00155BF0(void);
void func_001298E0(void);
s32 func_00138D70(s32);
void func_0012D9D8(s32, s32, s32);

// Add PAL C for func_0045FCB0
void func_0045FCB0(s32 a, s32 b, s32 c) {
    Stat st;
    u8 buf[0x40];
    s32 n;
    s32 i;

    func_00449B28(5, 0);
    func_00163990();
    func_004E5B78(1);
    func_00163990();
    func_00163550(1);
    if (D_0021EE54 == 1 && D_00172444[0] != 0) {
        func_01E9A858(&st, buf, 0x40);
        n = 5000;
        if (st.x30 != 5 && st.x30 != 0) {
            func_01E9A7C8();
        }
        do {
            func_0015A080();
            func_01E9A858(&st, buf, 0x40);
            func_00127A08(0x1F4);
            if (st.x30 == 5 || st.x30 == 0) {
                break;
            }
        } while (--n != -1);
        func_01E9A590(0);
        func_01E9A0F0();
    }
    func_00131A08(0, 0);
    func_00139940(0);
    func_00127600(2);
    for (i = 0; i < 8; i++) {
        func_0013B810(i >= 4, i % 4);
    }
    func_0013B088(0);
    func_0013B088(1);
    func_0013B460();
    func_0013AFF8();
    func_0013A7A0(0, 0, 0);
    func_0013A0F0();
    if (D_0021EE54 == 1) {
        func_00159FA8();
    }
    func_001376B0(5);
    if (D_0021EE54 == 1) {
        func_0045FC78(D_0021EF80);
        func_00155BF0();
    }
    func_001298E0();
    n = 0x78;
    do {
        n--;
        func_00138D70(0);
    } while (n > 0);
    func_0012D9D8(a, b, c);
}
