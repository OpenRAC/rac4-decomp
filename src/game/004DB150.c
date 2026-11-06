#include "common.h"
typedef struct {
    int f0, flags;
    char pad[0x1398];
    int id;
    unsigned char changed, active;
} State;
extern State D_00321B98[];
extern int D_0021EDD4, D_0021EDD8;
extern void func_00497980(int);
void func_004DB150(int id)
{
    State *p = D_00321B98;
    if (!D_0021EDD4 && D_0021EDD8 == 1 && p->active) {
        if (p->id != id) {
            p->id = id;
            p->flags |= 3;
            p->changed = 1;
            p->active = 0;
            func_00497980(8);
        } else
            func_00497980(4);
    }
}
