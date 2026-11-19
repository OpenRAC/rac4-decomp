/* Not matching yet: BYTES 3/176 (tools/try_func.py func_0053F600 --diff). Not part of the build. */
extern s32 D_0021EDD4;
extern s32 func_0053CC88(void *arg0);

s32 func_0053F600(void *arg0, s32 arg1) {
    void *temp_v0;
    unsigned char flags;

    if (*(s32 *)((unsigned char *)arg0 + 0x98) != 0) {
        temp_v0 = (void *)func_0053CC88(arg0);
        if (temp_v0 == 0) {
            return 0;
        }
        if (*(float *)((unsigned char *)temp_v0 + 0x2E8) <= 0.0f) {
            return 0;
        }
        if (D_0021EDD4 != 1) {
            return 0;
        }
        flags = *(unsigned char *)((unsigned char *)arg0 + 0xBE);
        if (flags & 0x18) {
            if (!(flags & 8) || arg1 != D_0021EDD4) {
                if (flags & 0x10) {
                    if (arg1 == 0) {
                        return 0;
                    }
                }
            } else {
                return 0;
            }
        }
        return 1;
    }
    return 0;
}
