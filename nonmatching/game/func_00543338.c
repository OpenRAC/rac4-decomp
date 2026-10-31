/* Not matching yet: BYTES 10/92 (tools/try_func.py func_00543338 --diff). Not part of the build. */
/* func_00543338: calls the per-slot routine for each live slot, then clears the live count */
s32 D_00220E4C = 0;
extern s8 D_354EA0[];
void func_005433E0(void *);

void func_00543338(void) {
    s32 i = 0;
    u8 *p;

    if (D_00220E4C > 0) {
        p = D_354EA0;
        do {
            i++;
            func_005433E0(p);
            p += 0x18;
        } while (i < D_00220E4C);
    }
    D_00220E4C = 0;
}
