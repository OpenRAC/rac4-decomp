/* Not matching yet: SIZE ours 172 / retail 168 (tools/try_func.py func_01EC5150 --diff). Not part of the build. */
/* cflags: @ee32-040921 -O2 -G0 */
typedef struct Node_s {
    s32 unk0;
    s32 pad4;
    s32 unk8;
    u8 padC[0x88];
    void *unk94[2];
    s32 unk9C;
} Node;

extern s32 func_01EC52B8(s32 arg0);

s32 func_01EC5150(Node *arg0) {
    u32 i = 0;
    void **p;
    void *temp;

    if (arg0 == 0 || (u32)arg0->unk8 < 2) {
        return 0;
    }
    if (func_01EC52B8(arg0->unk9C) == 0) {
        return 0;
    }
    p = arg0->unk94;
    while (1) {
        temp = *p++;
        if (temp != 0) {
            if (arg0->unk0 != ((Node *)temp)->unk8) {
                return 0;
            }
            if (func_01EC52B8(temp) == 0) {
                return 0;
            }
        }
        if (++i >= 2) {
            break;
        }
    }
    return 1;
}
