/* Not matching yet: BYTES 24/128 (tools/try_func.py func_L01_0054D320 --diff). Not part of the build. */
extern s32 *D_0021DDA4;
extern f32 D_222A50[];

typedef struct {
    u8 pad0[0xC8];
    s32 field;
    u8 pad1[0x470 - 0xC8 - 4];
} Entry;

extern Entry D_2302E0[];

s32 func_L01_0054D320(f32 fparg0) {
    s32 a3 = 1;
    s32 i;

    for (i = 0; i < *D_0021DDA4; i++) {
        f32 t = D_222A50[i] - fparg0;
        D_222A50[i] = t;
        D_2302E0[i].field = 0;
        if (t <= 0.0f) {
            D_222A50[i] = 0.0f;
        } else {
            a3 = 0;
        }
    }
    return a3;
}
