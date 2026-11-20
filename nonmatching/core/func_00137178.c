/* Not matching yet: SIZE ours 64 / retail 84, a call-ABI wall: retail saves $gp (daddu $s0,$gp), loads D_1AD5CC into $gp for the jalr and restores it. No C construct emits that sequence, so the body cannot reach retail's extent. (tools/try_func.py func_00137178 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
extern s32 D_00165FE4[];
extern void (*D_1AD5C8[])(s32, void *);
extern s32 D_1AD5CC[];
extern s32 D_1AD5D0[];

void func_00137178(void) {
    if (D_1AD5C8[0] != 0) {
        if (D_00165FE4[0] == 0) {
            D_1AD5C8[0](D_1AD5D0[0], D_1AD5C8[0]);
        }
    }
}
