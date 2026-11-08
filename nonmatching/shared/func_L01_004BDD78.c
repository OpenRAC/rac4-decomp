/* Not matching yet: SIZE ours 20 / retail 24 (tools/try_func.py func_L01_004BDD78 --diff). Not part of the build. */
extern u32 D_00171C14;

/* True when bit 26 of a global word is set. */
s32 func_L01_004BDD78(void) {
    return !!(D_00171C14 & 0x04000000);
}
