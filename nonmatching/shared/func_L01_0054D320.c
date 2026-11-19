/* Not matching yet: BYTES 47/128 (tools/try_func.py func_L01_0054D320 --diff). Not part of the build. */
extern s32 *D_0021DDA4;
extern f32 D_222A50[];
extern u8 D_2302E0[];

typedef struct {
    u8 pad0[0xC8];
    s32 field;
    u8 pad1[0x470 - 0xC8 - 4];
} Entry;

s32 func_L01_0054D320(f32 fparg0) {
    f32 zero = 0.0f;
    Entry *entries = (Entry *)D_2302E0;
    s32 a3 = 1;
    s32 i;

    for (i = 0; i < *D_0021DDA4; i++) {
        f32 t = D_222A50[i] - fparg0;
        D_222A50[i] = t;
        entries[i].field = 0;
        if (t <= zero) {
            D_222A50[i] = zero;
        } else {
            a3 = 0;
        }
    }
    return a3;
}
