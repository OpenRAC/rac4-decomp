/* Not matching yet: SIZE ours 124 / retail 136 (tools/try_func.py func_L00_005206E8 --diff). Not part of the build. */
typedef struct {
    s32 unk0;
    s32 unk4;
    s32 unk8;
    s32 unkC;
} S;

extern void *func_004FAD00();
extern void *func_L00_004FACD8();

s32 func_L00_005206E8(S *s, s32 n) {
    s32 old;
    void *p;
    if (s->unk8 < n) {
        if (n > 0) {
            old = s->unk8;
            if (s->unkC == 0) {
                p = func_L00_004FACD8(n * 4);
            } else {
                p = func_004FAD00((void *)s->unkC, n * 4, old * 4);
            }
            if (p != 0) {
                s->unk8 = n;
                s->unkC = (s32)p;
                return 0;
            }
            return 1;
        }
        return 0;
    }
    return 0;
}
