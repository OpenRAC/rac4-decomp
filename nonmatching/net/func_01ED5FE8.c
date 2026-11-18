/* Not matching yet: SIZE ours 168 / retail 176 (tools/try_func.py func_01ED5FE8 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct NetObj NetObj;
struct NetObj {
    s32 f0;
    s32 f4;
    s32 f8;
};

extern s32 D_00169CD0;
extern s32 D_00169CD4;
extern s32 D_00169D44;
extern s32 D_00169D4C[];
extern void func_01ED9358();
extern s32 func_01E9E8C8(s32 *);
extern void func_01ED5F90();

s32 func_01ED5FE8(NetObj *arg0, s32 arg1)
{
    s32 local;
    s32 v;

    if (arg0 == NULL)
        return -0x15;
    if (arg0->f0 == 0)
        return -0x15;
    if (arg0->f8 == 0)
        return -0x15;
    if (D_00169CD0 != 1)
        return -0xF;
    if (D_00169CD4 == 0)
        return -0x10;
    D_00169D44 = arg0->f8;
    func_01ED9358(&D_00169CD4, 1, arg0, arg0->f8, arg0->f0, arg0->f4,
                  &func_01ED5F90, arg1);
    D_00169D4C[0] = 0;
    v = func_01E9E8C8(&local);
    D_00169CD4 = 0;
    return v == 0 ? 0 : -3;
}
