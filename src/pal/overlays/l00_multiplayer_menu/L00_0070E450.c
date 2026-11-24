#include "common.h"
#include "pal/global_002234A4.h"

typedef struct Ctx {
    u8 pad0[0x3C];
    u8 *x3C;
} Ctx;

typedef struct Msg {
    s32 x0;
    s32 x4;
    s32 x8;
    u8 padC[0xF];
    char text[0x185];
} Msg;

typedef struct Ids {
    s32 x0;
    u8 pad4[0x8];
    s32 xC;
} Ids;

typedef struct Node {
    s32 x0;
    u8 pad4[0x4];
    s32 x8;
    u8 padC[0x190];
    struct Node *x19C;
} Node;

extern Ids D_003F3D58;
s32 D_00220AF4 = -1;
s32 D_00220AF8 = -1;
extern u8 D_00220B0C;
extern Node *D_00220AC0;
extern char D_00220B18[];
extern char *func_0011A9EC(char *, char *);
extern s32 func_0011D920(char *, const char *, ...);
extern s32 func_L00_0070D8B0(Msg *);
extern void func_L00_0070DDF8(s32, s32);

// Sends a message for (a, b) through func_L00_0070D8B0 and remembers the pair
// in D_00220AF4/D_00220AF8 (both reset to -1 if sending fails). If the flag
// D_00220B0C is set, finds the matching node in the list at D_00220AC0, sends
// a second message for it, calls func_L00_0070DDF8 and clears the flag.
s32 func_L00_0070E450(s32 a, s32 b)
{
    Msg m;
    Msg m2;
    Node *n;
    s32 r;

    m.x0 = D_003F3D58.x0;
    m.x4 = 1;
    m.x8 = b;
    func_0011A9EC(m.text, (char *)((Ctx *)D_002234A4)->x3C + 4);
    D_00220AF4 = a;
    D_00220AF8 = b;
    r = func_L00_0070D8B0(&m);
    if (r == 0) {
        D_00220AF4 = -1;
        D_00220AF8 = -1;
    } else if (D_00220B0C != 0) {
        for (n = D_00220AC0; n != 0; n = n->x19C) {
            if (n->x0 == D_003F3D58.x0) {
                m2.x8 = n->x8;
                m2.x0 = D_003F3D58.xC;
                m2.x4 = 1;
                func_0011D920(m2.text, D_00220B18, 0x33E2, (char *)((Ctx *)D_002234A4)->x3C + 4);
                func_L00_0070D8B0(&m2);
                func_L00_0070DDF8(D_003F3D58.x0, n->x8);
                D_00220B0C = 0;
                break;
            }
        }
    }
    return r;
}
