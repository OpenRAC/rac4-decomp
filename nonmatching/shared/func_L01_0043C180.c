/* Not matching yet: BYTES 7/32 (tools/try_func.py func_L01_0043C180 --diff). Not part of the build. */
typedef int u128 __attribute__((mode(TI)));

extern u8 D_222D14[];

/* Copy the 16 bytes of the record the object's member selects. */
u128 func_L01_0043C180(void *arg0) {
    void *entry = *(void **)((u8 *)arg0 + 0xAC);
    s32 index = *(s32 *)((u8 *)entry + 0x68);

    return *(u128 *)(D_222D14 + (index << 8) + 0x10);
}
