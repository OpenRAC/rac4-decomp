/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern s32 func_L00_004FAAC0(s32 a, s32 b, void *c, s32 d);
extern void *func_L00_0051EB20(void);
extern void func_L00_0051EB68(void *object);
extern s32 func_L00_0051EBD0(void *arg0, s32 arg1, s32 arg2, s32 arg3, s32 arg4);
extern s32 D_004AE518[];

// Returns the cached object of the handle, creating and initialising it on first use.
void *func_L00_00526A08(s32 *arg0) {
    void *temp_v0;
    void *temp_v0_2;
    void *object;

    temp_v0 = (void *)arg0[3];
    if (temp_v0 == 0) {
        func_L00_004FAAC0(9, 9, D_004AE518, 0x352);
        temp_v0_2 = (void *)arg0[3];
        if (temp_v0_2 == 0) {
            object = func_L00_0051EB20();
            if (object != 0) {
                if (func_L00_0051EBD0(object, arg0[2], arg0[1], 0, 0) != 0) {
                    func_L00_0051EB68(object);
                    object = 0;
                } else {
                    arg0[3] = (s32)object;
                }
            }
        } else {
            object = temp_v0_2;
        }
        func_L00_004FAAC0(10, 9, D_004AE518, 0x367);
    } else {
        object = temp_v0;
    }
    return object;
}
