/* Not matching yet: BYTES 5/136 (tools/try_func.py func_L00_005184C8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
extern s32 func_L00_0051A258(s32 *);
extern s32 *func_L00_0051A350(void);
extern void func_L00_0051A628(s32 *);
s32 func_L00_005184C8(void *arg0) {
    s32 value;
    if (*(s32 **)((u8 *)arg0 + 0x1C) != 0) {
        func_L00_0051A628(*(s32 **)((u8 *)arg0 + 0x1C));
        *(s32 **)((u8 *)arg0 + 0x1C) = 0;
    }
    *(s32 **)((u8 *)arg0 + 0x1C) = func_L00_0051A350();
    if (*(s32 **)((u8 *)arg0 + 0x1C) == 0) return 0x2715;
    value = ((s32 (*)(void))*(s32 *)(*(s32 *)((u8 *)arg0 + 4) + 0x20))();
    **(s32 **)((u8 *)arg0 + 0x1C) = value;
    if (value == 0) return 0x2711;
    return func_L00_0051A258(*(s32 **)((u8 *)arg0 + 0x1C)) != 0 ? 0 : 0x2711;
}
