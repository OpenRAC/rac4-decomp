/* Not matching yet: BYTES 62/100 (tools/try_func.py func_L10_004D5430 --diff). Not part of the build. */
extern void func_L00_005B0038(void *, void *, s32);
extern void func_L10_004D4CF0(void);
extern u8 D_222698[];

void func_L10_004D5430(s32 arg0, void *arg1) {
    u8 *p = (u8 *)arg1;
    u8 *q;
    if (p[0x450] != 0) {
        p[0x450] = p[0x450] - 1;
        q = p + 0x452;
        do {
            if (*q != 0) {
                *q = *q - 1;
            }
            q++;
        } while ((s32)q < (s32)(p + 0x454));
    }
    func_L00_005B0038(D_222698, func_L10_004D4CF0, arg0);
}
