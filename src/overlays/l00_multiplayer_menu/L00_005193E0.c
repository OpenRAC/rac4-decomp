/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_L00_00519050(s32 arg0);
extern s32 func_L00_00520488(s32, s32, s32);
extern s32 func_L00_00520850(s32, s32, s32, s32);
extern s32 func_L00_00540108(s32 arg0);

/* Looks up the record for arg0[2], sets its two tags and returns it, or NULL when either step fails. */
s32 func_L00_005193E0(s32 *arg0) {
    s32 temp;

    temp = func_L00_00540108(arg0[2]);
    if (temp != 0) {
        if (func_L00_00520488(((s32 *)temp)[1], arg0[1], 0x12) != 0) {
            func_L00_00520850(((s32 *)temp)[1], 0x12, 3, 0);
            func_L00_00520850(((s32 *)temp)[1], 0x12, 4, 0);
            return temp;
        }
        func_L00_00519050(temp);
    }
    return 0;
}
