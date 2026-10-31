/* Not matching yet: BYTES 14/108 (tools/try_func.py func_00473778 --diff). Not part of the build. */
extern s32 func_0045CB50(void);
extern u8 D_00171B40[];

// Step the byte counter at +0x1E, and reset both counters when the step reaches half.
void func_00473778(void) {
    u8 *p;
    u8 v;
    s32 t;
    if (func_0045CB50() != 0) {
        p = D_00171B40;
        if ((p[0x1E] + 1) < 0x14) {
            v = p[0x1F] + 1;
            p[0x1F] = v;
            t = p[0x1E] + 1;
            if ((v & 0xFF) >= (t >> 1)) {
                p[0x1E] = (u8) t;
                p[0x1F] = 0;
            }
        }
    }
}
