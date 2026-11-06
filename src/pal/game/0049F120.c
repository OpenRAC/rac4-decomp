#include "common.h"
typedef struct {
    char pad[0x14];
    s32 choice;
    void (*callback)(s32);
    char rest[0x1E4];
} State;
extern State D_00307320[], D_00307174[];
extern void func_0049FC68(s32);
extern s32 func_004E17B8(void);
void func_0049F120(s32 index)
{
    State *p;
    if (index == 4)
        p = D_00307174;
    else
        p = D_00307320 + index;
    func_0049FC68(index);
    if (!p->choice) {
        func_004E17B8();
        func_004E17B8();
    } else {
        func_004E17B8();
        func_004E17B8();
    }
    if (p->callback)
        p->callback(p->choice);
}
