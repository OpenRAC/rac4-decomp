/* Not matching yet: SIZE ours 152 / retail 144 (tools/try_func.py func_01ED5A90 --diff). Not part of the build. */
/* cflags: -G0 */
extern s32 D_00169CD4[];
extern s16 D_00169CD8[];

extern void (*func_01ED5B38(void))(s32, s32);
extern s32 func_01ED5B48(void);
extern void func_01ED8338(s32, s32);

void func_01ED5A90(s32 *arg0) {
    s32 temp_a1 = arg0[1];

    if (temp_a1 != 1) {
        D_00169CD4[0] = arg0[0];
    } else {
        s32 temp_a0 = arg0[0];

        D_00169CD4[0] = temp_a0;
        if (D_00169CD8[0] == temp_a1) {
            func_01ED8338(temp_a0, temp_a1);
        }
    }
    if (func_01ED5B38() != 0) {
        func_01ED5B38()(D_00169CD4[0], func_01ED5B48());
    }
}
