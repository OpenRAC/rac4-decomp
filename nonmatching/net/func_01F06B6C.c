/* Not matching yet: BYTES 14/124 (tools/try_func.py func_01F06B6C --diff). Not part of the build. */
/* extern */
extern void func_0011A518(void *, s32, s32);
s8 func_01F06BE8(void *, void *);
void func_01F0C090(void *, s32);
extern u8 D_0019E360[];

/* Fills arg0 with bytes from func_01F06BE8 until arg0[n] is zero, then clears the rest through func_0011A518. */
void func_01F06B6C(s8 *arg0) {
    s32 n;
    s32 i;

    if (arg0 == 0) {
        func_01F0C090(D_0019E360, 0xA5);
    }
    n = 0;
    i = 0;
    do {
        arg0[i] = func_01F06BE8(arg0, &n);
        i += 1;
    } while (arg0[n] != 0);
    func_0011A518(arg0 + i, 0, n - i);
}
