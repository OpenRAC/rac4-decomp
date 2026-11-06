/* Not matching yet: BYTES 3/188 (tools/try_func.py func_004BF658 --diff). Not part of the build. */
extern u8 D_0030B358[];
s32 func_00505B20(void);

static inline s32 func_004BF658_get(s32 base, s32 i)
{
    if (i < 0) {
        i = *(s32 *)(base + 0x54);
        if (i < 0) {
            return 0;
        }
    }
    return *(s32 *)(base + 0x34) + i * 0x18;
}

/* Return the index of the first entry whose record is active and not flagged, or -1. */
s32 func_004BF658(void)
{
    s32 obj;
    s32 base;
    s32 i;
    s32 rec;
    s32 found;
    s32 first;



    obj = (s32)(D_0030B358 + func_00505B20() * 0x258);
    found = -1;
    first = 1;
    base = obj + 0x1EC;
    for (i = 0; i < *(s32 *)(base + 0x50); i++) {
        rec = *(s32 *)(func_004BF658_get(obj + 0x1EC, i) + 8);
        if (*(u8 *)(rec + 2) != 0 && *(u8 *)(rec + 0) == 0 && first) {
            found = i;
            first = 0;
        }
    }
    return found;
}
