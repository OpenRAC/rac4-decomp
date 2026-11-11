/* Not matching yet: SIZE ours 48 / retail 52 (tools/try_func.py func_01EC2928 --diff). Not part of the build. */
/* Call the object's handler at 0x44 with its six arguments. */
s32 func_01EC2928(void *arg0, s32 arg1, s32 arg2, s32 arg3) {
    s32 (*handler)(void *, s32, s32, s32, s32, s32) = *(void **)((u8 *)arg0 + 0x44);

    return handler(arg0, arg1, 0, arg2, arg3, *(s32 *)((u8 *)arg0 + 0x48));
}
