/* Not matching yet: SIZE ours 188 / retail 180 (tools/try_func.py func_01ECEEC8 --diff) (tools/try_func.py func_01ECEEC8 --diff). Not part of the build. */
typedef struct {
    char pad00[0xC];
    s32 unkC;
    char pad10[0x10];
    s32 unk20;
} Node;

extern s32 func_01EA47E8(s32 *table, u32 index);
extern void func_01EA0368(s32 *arg0, u32 arg1);
extern void func_01ECF1A0(s32 *arg0, u32 arg1, u32 arg2, u32 arg3);

s32 func_01ECEEC8(s32 *arg0, s32 arg1, u32 arg2, u8 *arg3) {
    Node *temp_v0;
    s32 temp_s2;

    if (arg0 != 0 && arg2 < 0x100) {
        temp_v0 = (Node *)func_01EA47E8(arg0, arg3[1]);
        if (temp_v0 != 0 && temp_v0->unk20 != 0) {
            temp_s2 = arg0[0x101];
            temp_v0->unkC = arg3[0];
            if (temp_s2 != 0x100) {
                func_01EA0368(arg0, arg3[1]);
                if (((Node *)arg0[temp_s2])->unkC == 5) {
                    func_01ECF1A0(arg0, arg3[1], arg3[2], arg3[3]);
                }
                return 4;
            }
        }
    }
    return -1;
}
