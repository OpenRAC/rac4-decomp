#include "common.h"

typedef struct State {
    s32 count;
    s32 a[40];
    s32 b[40];
    s32 c[40];
    s32 d[40];
    s32 e[40];
} State;

extern State D_00266860;
extern u8 D_00243850[];
extern s16 D_00243570[];
extern s16 D_00243750[];
extern s32 D_00242D00[];
extern s32 D_00246AF0[];
extern s32 D_002214F8;
extern s32 D_002214FC;
extern s32 D_00221500;
extern s32 D_0021DAB4;

void func_00464E28(void)
{
    s32 *pc;
    s32 *pd;
    s32 id;
    s32 a;
    s32 b;
    s32 c;
    u8 value;

    if (D_00266860.count == 0) {
        return;
    }
    D_00266860.count--;
    id = D_00266860.a[D_00266860.count];
    value = D_00243850[id];
    if (D_00243570[value] == id) {
        D_002214F8--;
        D_00243850[id] = 0xFF;
        D_00243570[D_002214F8] = -1;
        D_00242D00[D_002214F8] = 0;
    } else if (D_00243750[value] == id) {
        D_00243850[id] = 0xFF;
        D_002214FC--;
        D_00243750[D_002214FC] = -1;
    }
    pd = &D_00266860.d[D_00266860.count];
    pc = &D_00266860.c[D_00266860.count];
    a = D_00266860.a[D_00266860.count];
    b = *pd;
    c = *pc;
    D_00266860.a[D_00266860.count] = 0;
    D_00243850[a] = 0xFF;
    D_00246AF0[D_002214F8] = 0;
    D_00266860.b[D_00266860.count] = 0;
    D_00221500 = c;
    D_0021DAB4 = b;
    D_00266860.c[D_00266860.count] = 0;
    D_00266860.d[D_00266860.count] = 0;
    D_00266860.e[D_00266860.count] = 0;
}
