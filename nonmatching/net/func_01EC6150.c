/* Not matching yet: SIZE ours 148 / retail 160 (tools/try_func.py func_01EC6150 --diff). Not part of the build. */
extern s32 func_01EA9850(void *arg0, u16 *arg1);
extern s32 func_01EC51F8(s32 arg0);

s32 func_01EC6150(void *arg0, s32 unused, void *arg2, u32 arg3) {
    s32 ret = 0xCB20;
    u16 buf;
    s32 (*fn)(s32, s32, s32, s32);

    if (arg3 > 1) {
        func_01EA9850(arg2, &buf);
        *(s32 *)((u8 *)arg0 + 0x78) = buf;
        if (*(u8 *)((u8 *)arg0 + 0x6C) == 0) {
            *(s32 *)((u8 *)arg0 + 0x78) = 1;
        }
        *(s32 *)((u8 *)arg0 + 0x8) = 8;
        fn = *(s32 (**)(s32, s32, s32, s32))((u8 *)arg0 + 0xA4);
        ret = 0;
        if (fn != 0) {
            fn(*(s32 *)((u8 *)arg0 + 0xA0), 1, *(s32 *)((u8 *)arg0 + 0x64),
               *(s32 *)((u8 *)arg0 + 0x78));
            ret = 0xCB23;
            if (func_01EC51F8(*(s32 *)((u8 *)arg0 + 0x0)) != 0) {
                ret = 0;
            }
        }
    }
    return ret;
}
