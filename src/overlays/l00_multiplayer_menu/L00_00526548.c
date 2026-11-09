/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_L00_00526A08(s32 arg0);
extern s32 func_L00_0051EE28(void *arg0, s32 arg1, s32 arg2, s32 *arg3);
extern void func_L00_00541430(s32 arg0, s32 *arg1, s32 arg2, char *arg3, s32 arg4, s32 arg5);
extern s32 func_00541170(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5, s32 arg6);
extern char D_004AE4E0[];
extern char D_004AE4F0[];
extern char D_004AE4F8[];
extern char D_004AE500[];
extern char D_004AE510[];

s32 func_L00_00526548(s32 arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4, s32 arg5) {
    s32 id;
    s32 len;
    char *name;
    void *obj;
    s32 result = -1;

    obj = func_L00_00526A08(arg5);
    if (obj != 0) {
        if (func_L00_0051EE28(obj, 0x103, 0, &id) == 0) {
        switch (arg0) {
        case 4:
            name = D_004AE4E0;
            break;
        case 0x29:
            name = D_004AE4F0;
            break;
        case 0x40:
            name = D_004AE4F8;
            break;
        case 3:
            name = D_004AE500;
            break;
        case 0x75:
            name = D_004AE510;
            break;
        default:
            goto end;
        }
        func_L00_00541430(arg3, &len, 10000, name, arg1, arg2);
        if (func_00541170(obj, arg3, arg4, id, arg3, len, 0) == 0) {
            result = id;
        }
        }
    }
end:
    return result;
}
