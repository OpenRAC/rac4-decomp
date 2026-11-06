#include "common.h"

typedef struct Type1 {
    char _p0[0x40];
    s32 f40;
    s32 f44;
    s32 f48;
    f32 f4C;
} Type1;

extern s32 func_0049A6E0(f32 *value, f32 target);
extern void func_004A5688(void);
extern void func_004A5720(void);
extern void func_004A5978(void);
extern void func_004A5F08(void);
extern void func_005014B0(s32 a0);
extern s32 func_00505B20(void);
extern Type1 D_00307F68[];

void func_004A5588(s32 a0) {
    Type1 *s;

    s = &D_00307F68[func_00505B20()];
    switch (s->f40) {
    case 1:
        break;
    case 0:
        if (!(u8)func_0049A6E0(&s->f4C, 1.0f)) {
            s->f40 = 1;
        }
        func_004A5688();
        break;
    case 2:
        if (!(u8)func_0049A6E0(&s->f4C, 0.0f)) {
            func_005014B0(a0);
        }
        func_004A5688();
        break;
    }
    func_004A5720();
    if (s->f44 != 0) {
        func_004A5978();
    }
    func_004A5F08();
}
