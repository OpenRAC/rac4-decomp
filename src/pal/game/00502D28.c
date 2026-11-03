#include "common.h"
typedef struct {
    s32 f0;
    char *state;
} Manager;
extern Manager D_00222138[];
extern Manager *func_00502150(void);
extern s32 func_004490A8(s32);
extern char *func_00449060(s32);
extern void func_00502C10(f32, f32, f32, f32), func_00502C38(void);
s32 D_00220B9C = 0;
extern s32 *D_0021DE2C;
extern u8 D_00171E6B[];
void func_00502D28(void)
{
    Manager *m = D_00222138;
    char *state;
    char *p;
    if (!m->state)
        m = func_00502150();
    state = m->state;
    p = func_00449060(func_004490A8(state ? *(s32 *)(state + 0x14) : -1));
    D_00220B9C = 0;
    if (*D_0021DE2C && D_00171E6B[0])
        func_00502C10(0.0f, 0.0f, 1.0f, *(f32 *)(p + 0x14));
    else
        func_00502C10(0.0f, 0.0f, *(f32 *)(p + 0x10), *(f32 *)(p + 0x14));
    func_00502C38();
}
