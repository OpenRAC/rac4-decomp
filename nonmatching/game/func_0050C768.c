/* Not matching yet: BYTES 14/108 (tools/try_func.py func_0050C768 --diff). Not part of the build. */
extern s32 func_005015C8(s32 *arg0);

// Calls func_005015C8 on each non-null pointer in the table at offset 0x40 (count at 0x1E8), then clears each entry.
void func_0050C768(void *arg0) {
    s32 i;
    s32 *p;
    s32 v;

    i = 0;
    if (*(s32 *)((u8 *)arg0 + 0x1E8) > 0) {
        p = (s32 *)((u8 *)arg0 + 0x40);
        do {
            v = *p;
            if (v != 0) {
                func_005015C8((s32 *)v);
            }
            *p = 0;
            i++;
            p++;
        } while (i < *(s32 *)((u8 *)arg0 + 0x1E8));
    }
}
