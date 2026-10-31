/* Not matching yet: BYTES 10/72 (tools/try_func.py func_01E9D9F8 --diff). Not part of the build. */
extern void *D_00167EEC[];

// Walks the list at D_00167EEC for the node whose key (0x10) matches a0's, copies a0's 0x14 and 0x8 fields into it, and returns 0.
s32 func_01E9D9F8(s32 *a0) {
    s32 *a1 = D_00167EEC[0];
    s32 v1;

    if (a1 == 0) {
        return 0;
    }
    v1 = a1[4];
    do {
        if (v1 == a0[4]) {
            a1[5] = a0[5];
            a1[2] = a0[2];
            a1 = 0;
        } else {
            a1 = (s32 *) a1[15];
        }
        if (a1 != 0) {
            v1 = a1[4];
        }
    } while (a1 != 0);
    return 0;
}
