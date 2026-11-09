/* Not matching yet: SIZE ours 96 / retail 92 (tools/try_func.py func_0015DFD8 --diff). Not part of the build. */
extern u8 D_00172160[];
extern s32 (*D_212148)(void);

/* Copy a table word into a slot, then run the current callback. */
s32 func_0015DFD8(s32 arg0, s32 arg1, s32 arg2) {
    s32 result = -1;
    u8 slot = D_00172160[arg2 + 0x6C9];

    if (slot < 0xA) {
        (*(s32 *)((u8 *)D_00172160 + slot * 4 + 0x6A0)) = *(s32 *)((u8 *)D_00172160 + 0x218);
    }
    if (D_212148 != 0) {
        result = D_212148();
    }
    return result;
}
