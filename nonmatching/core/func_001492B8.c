/* Not matching yet: SIZE ours 168 / retail 164 (tools/try_func.py func_001492B8 --diff) (tools/try_func.py func_001492B8 --diff). Not part of the build. */
extern f32 D_001A0388[];
extern f32 D_001A0390[];

s32 func_001492B8(f32 *arg0, s32 arg1, s32 arg2) {
    s32 last = arg1 - 1;
    s32 result = 0;

    if (arg2 < last) {
        if ((arg2 == 0) || (D_001A0388[0] * arg0[0] <= arg0[arg2])) {
            result = arg2;
            if (D_001A0388[1] * arg0[arg2] <= arg0[last])
                result = last;
        }
    } else {
        if (D_001A0390[0] * arg0[0] <= arg0[last])
            result = last;
    }
    return result;
}
