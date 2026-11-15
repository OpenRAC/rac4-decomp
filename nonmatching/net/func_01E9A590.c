/* Not matching yet: BYTES 17/136 (tools/try_func.py func_01E9A590 --diff). Not part of the build. */
/* cflags: -mno-abicalls -mno-split-addresses */
extern s32 func_0012C888(s32 arg0, s32 arg1, s32 arg2, s32 *arg3);
extern s32 func_0012CA90(s32 descriptor);
extern s32 D_1AD3A8[];
extern s32 D_1AD3AC[];

s32 func_01E9A590(s32 arg0) {
    s32 sp0;
    s32 *p;
    s32 *q;

    sp0 = 0;
    if (!(arg0 & 2)) {
        p = D_1AD3AC;
        if (*p != 0) {
            q = D_1AD3A8;
            if (func_0012C888(*q, 0, 0, &sp0) < 0) {
                return sp0;
            }
            sp0 = func_0012CA90(*q);
            if (sp0 < 0) {
                return sp0;
            }
            *p = 0;
            sp0 = 0;
            return 0;
        }
    }
    return 0;
}
