/* Not matching yet: BYTES 23/292 (tools/try_func.py func_L00_00538DE0 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
extern void func_L00_00538128(void *a0);
extern int func_L00_005382C8(int a1, int a2);
extern void func_L00_005383D0(void *a0, void *a1);
extern void func_L00_00538508(void *a0, int a1);
extern void func_L00_00538F08(int a0, int a1, int a2, int a3, int a4);

/* merges two buffers (arg1, arg2) into arg0 or a scratch entry of arg3 */
s32 func_L00_00538DE0(s32 *arg0, s32 *arg1, s32 *arg2, s32 *arg3) {
    s32 len1 = arg1[1];
    s32 len2 = arg2[1];
    s32 total;
    s32 flags;
    s32 *dst;

    if (len1 == 0 || len2 == 0) {
        func_L00_00538508(arg0, 0);
        return 1;
    }
    total = len1 + len2;
    flags = arg2[3] ^ arg1[3];
    if (arg0 == arg1 || arg0 == arg2) {
        dst = (s32 *)((u8 *)arg3 + (*arg3 * 0x14 + 0x18));
    } else {
        dst = arg0;
    }
    if (dst[2] < total) {
        if (func_L00_005382C8((int)dst, total) != 0) {
            dst[1] = total;
        } else {
            return 0;
        }
    } else {
        if (dst == 0) {
            return 0;
        }
        dst[1] = total;
    }
    func_L00_00538F08(dst[0], arg1[0], len1, arg2[0], len2);
    arg0[3] = flags;
    func_L00_00538128(dst);
    if (arg0 != dst) {
        func_L00_005383D0(arg0, dst);
    }
    return 1;
}
