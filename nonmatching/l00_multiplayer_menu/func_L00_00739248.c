/* Not matching yet: BYTES 57/160 (tools/try_func.py func_L00_00739248 --diff). Not part of the build. */
extern s32 func_00764D50(void);
extern s32 func_00764D58(s32);

void func_L00_00739248(u8 *arg0)
{
    u8 **p = (u8 **)(arg0 + 0xC4);
    u8 *base = arg0 + 0x2EC;
    s32 i;

    for (i = 0; i < func_00764D50(); i++) {
        u8 *vt = *(u8 **)(*p + 0x58);
        u8 *t = base + func_00764D58(i);
        ((void (**)(u8 *, s32))(vt + 0x64))[0](*p, *t ? 0x70B6AB9E : 0x80404040);
        p++;
    }
}
