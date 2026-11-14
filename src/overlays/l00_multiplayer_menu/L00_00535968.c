/* cflags: @ee29 -O2 -G0 */
#include "common.h"

extern void func_005362F8(void *);
extern s32 func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00535A10(s32);
extern s32 func_L00_00545F88(s32, s32, s32, s32, s32);

// Look up an entry with func_L00_00545F88; report errors via func_L00_004F84C8 and release it unless it is the caller's current one.
s32 func_L00_00535968(s32 *arg0, s32 arg1, s32 arg2) {
    s32 entry = func_L00_00545F88((s32)arg0, arg1, arg2, 0x17, 0);
    if (entry == 0) {
        func_L00_004F84C8(0xD, 0x87, 4, 0, 0);
        return 0;
    }
    if (func_L00_00535A10(entry) != 0) {
        return entry;
    }
    func_L00_004F84C8(0xD, 0x87, 0x7B, 0, 0);
    if (arg0 == 0 || *arg0 != entry) {
        func_005362F8((void *)entry);
    }
    return 0;
}
