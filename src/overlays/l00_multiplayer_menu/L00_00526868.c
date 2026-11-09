/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void *func_005262A8(void);
extern void func_L00_00526210(void *);
extern s32 func_L00_00541528(s32, s32, s32, void *);
extern s32 func_L00_00541648(s32, s32);
void *func_L00_00526868(void **arg0, s32 *arg1, s32 arg2) {
    s32 temp[4];
    void *object = 0;
    if (arg0 != 0) object = *arg0;
    if (object == 0) object = func_005262A8();
    if (object != 0) {
        if (func_L00_00541528(*(s32 *)((u8 *)object + 4), *arg1, arg2, temp) != 0 ||
            func_L00_00541648(*(s32 *)((u8 *)object + 4), 0) != 0) {
            if (arg0 != 0 && *arg0 == object) {
                object = 0;
            } else {
                func_L00_00526210(object);
                object = 0;
            }
        }
    }
    if (object != 0 && arg0 != 0) *arg0 = object;
    return object;
}
