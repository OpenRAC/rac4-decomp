#include "common.h"

typedef struct Text2 {
    char c[2];
} Text2;

typedef struct Msg {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 padC[0xF];
    char text[0x185];
    s32 value;
} Msg;

typedef struct Profile {
    u8 pad0[0xC];
    s32 xC;
    u8 pad10[0x4];
    s32 x14;
} Profile;

extern Profile D_001721E0;
extern s32 D_003F41D8[];
s32 D_00220BD8 = 0;
s32 D_00220BCC = -1;
extern char D_00220C80[];
extern char D_00220C90[];
extern void func_01E9E5D0(s32 *, s32);
extern s32 func_001614B8(void);
extern s32 func_0011D920(char *, const char *, ...);
extern void func_L00_0070D8B0(Msg *);

// Builds a message for id and passes it to func_L00_0070D8B0: with full set,
// its text is formatted from D_00220C80 with two mode letters and two values;
// otherwise it is the two-byte text at D_00220C90.
void func_L00_007135B8(s32 id, s32 full)
{
    Msg m;

    m.x0 = D_003F41D8[0];
    m.x4 = 1;
    m.x8 = id;
    if (full) {
        m.value = -1;
        if (D_00220BD8 == 1) {
            func_01E9E5D0(&m.value, D_001721E0.xC);
        }
        func_0011D920(m.text, D_00220C80, func_001614B8() ? 0x2B : 0x2D,
                      D_001721E0.x14 == 1 ? 0x31 : 0x32, D_00220BCC, m.value);
    } else {
        *(Text2 *)m.text = *(Text2 *)D_00220C90;
    }
    func_L00_0070D8B0(&m);
}
