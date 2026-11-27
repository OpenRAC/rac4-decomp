/* Not matching yet: BYTES 16/232 (tools/try_func.py func_L00_005AB468 --diff). Not part of the build. */
extern u16 D_0023A740[];
extern s32 D_0023AAD8[];
extern s32 func_L00_005AB2E8(s32, void *, u16 *);

s32 func_L00_005AB468(void) {
    u16 buf[4];
    u8 *p;
    u8 *t;
    u8 *e;
    s16 v;

    p = (u8 *)D_0023A740;
    if (*(s16 *)(p + 0x22) == -1) {
        *(s16 *)(p + 0x22) = 0;
        *(u16 *)(p + 0x24) = 0;
        return 1;
    }
    t = (u8 *)D_0023AAD8;
    e = t + 0x1C;
    if (func_L00_005AB2E8(*(s32 *)(e + *(s16 *)(p + 0x22) * 0x4C), buf,
                          (u16 *)((char *)buf + 4)) != 0) {
        if (*(s32 *)(e + *(s16 *)(p + 0x22) * 0x4C) != 0) {
            *(u16 *)(p + 0x22) = buf[0];
            *(u16 *)(p + 0x24) = *(u16 *)((char *)buf + 4);
            return 1;
        }
    }
    v = D_0023A740[17] + 1;
    D_0023A740[18] = 0;
    D_0023A740[17] = v;
    return v < D_0023AAD8[0x4C0];
}
