#include "common.h"

extern char D_00220B20[];
extern char D_00220B28[];
extern char D_00220B38[];
extern s32 func_0011AE00(char *, char *, s32);
extern void func_005024D0(char *arg0, s32 *arg1, u32 *arg2);
extern char *func_00502510(char *, s32, s32, s32, s32, s32);
extern char *func_00502A88(char *, s32, s32, s32);
extern char *func_00502DB8(char *, s32, s32, s32);
extern char *func_00502FE0(char *, s32, s32, s32);
extern char *func_005031D0(char *, s32, s32, s32);
extern char *func_005033D0(char *, s32, s32, s32);

char *func_00503708(char *p, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6)
{
    s32 type;
    u32 count;
    u32 i;

    type = 0;
    count = 0;
    do {
        if (func_0011AE00(D_00220B20, p, 7) == 0)
            break;
        if (func_0011AE00(D_00220B28, p, 15) == 0)
            break;
        if (func_0011AE00(D_00220B38, p, 15) == 0)
            break;
        func_005024D0(p, &type, &count);
        if (type == 9)
            break;
        p += 4;
        if (type == 5 && arg1 == 0)
            break;
        for (i = 0; i < count && p != 0; i++) {
            switch (type) {
            case 4:
            case 5:
                p = func_00502510(p, arg2, arg3, arg4, arg5, arg6);
                break;
            case 1:
                p = func_005031D0(p, arg3, arg4, arg5);
                break;
            case 2:
                p = func_00502FE0(p, arg3, arg4, arg5);
                break;
            case 3:
                p = func_00502A88(p, arg3, arg4, arg5);
                break;
            case 9:
                p = func_005033D0(p - 4, arg3, arg4, arg5);
                break;
            case 10:
                p = func_00502DB8(p, arg3, arg4, arg5);
                break;
            default:
                p = 0;
                break;
            }
        }
    } while (p != 0);
    return p;
}
