/* Not matching yet: BYTES 8/84 (tools/try_func.py func_01EDBC10 --diff). Not part of the build. */
extern void func_01ED5548(void *);
extern s32 D_1BC848[];
extern s32 D_1BCA40[];

/* Calls func_01ED5548 on the sub-object at +0x44 when the word at +0x18 is zero, then the optional handler D_1BCA40; returns 0xC4. */
s32 func_01EDBC10(s32 arg0, s32 arg1, s32 arg2, void *arg3) {
    u8 *sub;

    sub = (u8 *)arg3 + 0x44;
    if (*(s32 *)((u8 *)arg3 + 0x18) == 0) {
        func_01ED5548(sub);
    }
    if (D_1BCA40[0] != 0) {
        ((void (*)(void *, s32))D_1BCA40[0])(arg3, D_1BC848[0]);
    }
    return 0xC4;
}
