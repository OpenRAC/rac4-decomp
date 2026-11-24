#include "common.h"

typedef struct Roster {
    char name[10][16];
    char tag[10][8];
    u8 xF0[10];
    u8 xFA[10];
    u8 pad104[0xA];
    u8 x10E[10];
} Roster;

typedef struct Msg {
    s32 id;
    u8 b;
    u8 a;
    u8 c;
    char name[0x10];
    char tag[0x5];
    u8 pad1C[0x4];
} Msg;

typedef struct Profile {
    u8 pad0[0x8];
    s32 x8;
    u8 padC[0x248];
    s32 x254;
    s32 x258;
    u8 pad25C[0x59C];
    u8 x7F8;
} Profile;

extern Roster *D_0021E070;
extern Profile D_001721E0;
extern s32 D_0021DC58;
extern s32 func_00161330(void);
extern char *func_0011AFC8(char *, char *, s32);
extern void func_01E9E270(s32, s32, s32, s32, s32, Msg *);

// Stores the name, a 4-character tag and three values of entry id in the
// table at D_0021E070 when func_00161330 says so; otherwise sends them as a
// 0x20-byte message.
// Always returns 1.
s32 func_L00_007750B8(s32 arg0, s32 id, char *name, s32 a, s32 b, s32 c, char *tag)
{
    Msg m;

    if (func_00161330()) {
        func_0011AFC8(D_0021E070->name[id], name, 16);
        D_0021E070->name[id][15] = 0;
        D_0021E070->tag[id][0] = 0;
        if (tag) {
            func_0011AFC8(D_0021E070->tag[id], tag, 4);
            D_0021E070->tag[id][4] = 0;
        }
        D_0021E070->xFA[id] = b;
        D_0021E070->xF0[id] = a;
        D_0021E070->x10E[id] = c;
    } else {
        m.c = c;
        m.id = id;
        m.a = a;
        m.b = b;
        func_0011AFC8(m.name, name, 16);
        m.name[15] = 0;
        func_0011AFC8(m.tag, tag, 4);
        m.tag[4] = 0;
        if (D_001721E0.x258 == 0) {
            func_01E9E270(D_001721E0.x7F8 | 0x50, D_001721E0.x8, D_001721E0.x254, D_0021DC58, sizeof(Msg), &m);
        }
    }
    return 1;
}
