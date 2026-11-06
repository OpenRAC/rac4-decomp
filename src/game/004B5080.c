#include "common.h"
typedef struct {
    int f0, f4;
    float current, target;
    char pad[0x18];
    int timer;
    unsigned char changed;
} State;
extern State D_00309840[];
extern int func_004534D0(int *);
extern f32 func_004757E0(f32 *, f32, f32, f32);
extern void func_004B5138(void);
void func_004B5080(void)
{
    int changed = 0, refresh = 0;
    if (D_00309840[0].target != D_00309840[0].current) {
        if (D_00309840[0].timer)
            func_004534D0(&D_00309840[0].timer);
        else
            func_004757E0(&D_00309840[0].target, D_00309840[0].current, 0.1f, 0.005f);
        refresh = 1;
        changed = 1;
    } else
        D_00309840[0].timer = 30;
    if (refresh)
        func_004B5138();
    D_00309840[0].changed = changed;
}
