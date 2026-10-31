/* Not matching yet: BYTES 19/128 (tools/try_func.py func_01EE1550 --diff). Not part of the build. */
extern s32 func_0011A2DC();
extern s32 D_0016AA98_[];
#define D_0016AA98 (D_0016AA98_[0])

// Scans the 0x18-byte table at D_0016AA98 for an entry whose key matches arg1 and whose callback accepts it; returns that entry's first word, or 0.
s32 func_01EE1550(s32 arg0, s32 arg1) {
    s32 *e = D_0016AA98_;

    while (e[0] != 0) {
        if (arg1 == e[1] && func_0011A2DC(arg0, (s32 *)((u8 *)e + 8), arg1) == 0) {
            return e[0];
        }
        e = (s32 *)((u8 *)e + 0x18);
    }
    return 0;
}
