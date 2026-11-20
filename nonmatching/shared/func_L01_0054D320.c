/* Not matching yet: BYTES 22/128 (tools/try_func.py func_L01_0054D320 --diff). Not part of the build. */
/* cflags: -fno-gcse */
extern s32 *D_0021DDA4;
extern u8 D_222A50[];

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
        f32 t = *(f32 *)(D_222A50 + i * 4);
        D_2302E0[i].field = 0;
        t = t - fparg0;
        *(f32 *)(D_222A50 + i * 4) = t;
        if (t <= 0.0f) {
            *(f32 *)(D_222A50 + i * 4) = 0.0f;
        } else {
            a3 = 0;
        }
    }
    return a3;
}
