/* Not matching yet: SIZE ours 44 / retail 56 (tools/try_func.py func_00159570 --diff). Not part of the build. */
s32 D_0021DCB4 = 0;

extern u8 D_1C1F80[];

/* Table word 0x10, filling the table first when it is not ready yet. */
s32 func_00159570(void) {
    if (D_0021DCB4 == 0) {
        func_00137FB0();
    }
    return (*(s32 *)(D_1C1F80 + 0x10));
}
