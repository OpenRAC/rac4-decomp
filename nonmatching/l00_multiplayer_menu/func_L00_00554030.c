/* Not matching yet: BYTES 8/32 (tools/try_func.py func_L00_00554030 --diff). Not part of the build. */
/* Link the object into the list at 0x20, set a flag, and return null. */
void *func_L00_00554030(void *arg0, void *arg1) {
    void *result = 0;

    (*(s32 *)((u8 *)arg1 + 0x1C)) = *(s32 *)((u8 *)arg0 + 0x20);
    (*(s32 *)((u8 *)arg0 + 0x20)) = (s32)arg1;
    (*(u8 *)((u8 *)arg0 + 0x16)) |= 8;
    return result;
}
