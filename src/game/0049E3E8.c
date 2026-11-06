#include "common.h"
typedef struct {
    char pad[0x14];
    s32 choice;
    void (*callback)(s32);
    char rest[0x1E4];
} State;
extern State D_00307220[], D_00307074[];
extern void func_0049EF30(s32);
extern s32 func_004E0858(void);
void func_0049E3E8(s32 index)
{
    State *p;
    if (index == 4)
        p = D_00307074;
    else
        p = D_00307220 + index;
    func_0049EF30(index);
    if (!p->choice) {
        func_004E0858();
        func_004E0858();
    } else {
        func_004E0858();
        func_004E0858();
    }
    if (p->callback)
        p->callback(p->choice);
}
