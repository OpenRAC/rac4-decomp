/* cflags: @ee29 -O2 -G8 */
#include "common.h"

extern void func_004FAD28(void *);
extern void func_00530210(s32);
extern void func_005362F8(s32);
extern void func_00542440(s32);
extern void func_L00_00508310(s32, void *);
extern void func_L00_0052FA40(s32);
extern void func_L00_00536958(s32);
extern s32 func_L00_0052F6C0[];
void func_L00_0052F258(void *arg0) {
    if (arg0 != 0) {
        func_005362F8(*(s32 *)((u8 *)arg0 + 0));
        func_005362F8(*(s32 *)((u8 *)arg0 + 4));
        func_00542440(*(s32 *)((u8 *)arg0 + 8));
        func_L00_00536958(*(s32 *)((u8 *)arg0 + 0xC));
        func_00530210(*(s32 *)((u8 *)arg0 + 0x10));
        func_L00_00536958(*(s32 *)((u8 *)arg0 + 0x14));
        func_L00_0052FA40(*(s32 *)((u8 *)arg0 + 0x18));
        func_005362F8(*(s32 *)((u8 *)arg0 + 0x1C));
        func_005362F8(*(s32 *)((u8 *)arg0 + 0x20));
        func_L00_00508310(*(s32 *)((u8 *)arg0 + 0x24), func_L00_0052F6C0);
        func_004FAD28(arg0);
    }
}
