/* Not matching yet: BYTES 120/196 (tools/try_func.py func_01EFA964 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -fno-gcse -mno-split-addresses */
s32 func_01EFA964(u8 *p, s32 arg1)
{
    s32 idx = *(s32 *)(p + 0xD0);
    s32 off = idx * 3;
    s32 next = idx + 1;

    if (idx >= *(s32 *)(p + 0xBC)) {
        return 0;
    }
    {
        u8 *base = *(u8 **)(p + 0x118);
        s32 ec = *(s32 *)(p + 0xEC);
        s8 c = *(s8 *)(*(s32 *)(p + 0xB4) + arg1);
        s32 fc = *(s32 *)(p + 0xFC);
        s32 f8 = *(s32 *)(p + 0xF8);
        s32 max = *(s32 *)(p + 0x100);
        s32 ec1 = ec + 1;
        s32 fc1 = fc + 1;
        s32 f8p = f8 + 1;
        s32 less = fc < max;
        u8 *v = base + off * 4;

        *(s16 *)(v + 2) = arg1;
        if (c == 0x20 || c == 0xA) {
            *(s16 *)(v + 0xC) = arg1 + 1;
        } else {
            *(s16 *)(v + 0xC) = arg1;
        }
        *(s32 *)(p + 0xEC) = ec1;
        *(u16 *)(base + off * 4 + 0x10) = *(u16 *)(p + 0xEC);
        if (less) {
            *(s32 *)(p + 0xFC) = fc1;
        } else {
            *(s32 *)(p + 0xF0) = *(s32 *)(p + 0xF0) + 1;
        }
        *(s32 *)(p + 0xD0) = next;
        *(s32 *)(p + 0xF8) = f8p;
        *(s32 *)(p + 0x10C) = 0;
        return 1;
    }
}
