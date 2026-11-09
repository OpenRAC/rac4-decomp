/* Not matching yet: BYTES 2/204 (tools/try_func.py func_L00_0076F770 --diff). Not part of the build. */
typedef struct {
    u16 f0;
    u8 pad2[0x13];
    u8 f15[0x13];
    s32 f28;
} Type1;

extern void func_0011A9EC(void *, void *);
extern u64 func_0012E370(void);
extern u64 func_0012FEB0(u64, u64);
extern void func_0015B548(s32 val);
extern s32 func_0015B558(void);
extern s32 func_1ED6E48(void *, void *, s32);
extern void func_0015D1F0(void);
extern u16 D_00221808[];
extern s32 D_002233A4;

/* Set up a request record, submit it, and flag state 0x39 on failure. */
s32 func_L00_0076F770(u8 *arg0) {
    Type1 rec;
    s32 ret;
    u8 *s;

    ret = 1;
    s = (u8 *)D_002233A4;
    *(s32 *)(arg0 + 0xF94) = 0;
    rec.f0 = D_00221808[0];
    func_0011A9EC(rec.f15, *(void **)(s + 0x64));
    rec.f28 = *(s32 *)0x172284;
    arg0[0x12] = 1;
    *(s32 *)(arg0 + 0x18) = func_0012FEB0(func_0012E370(), 0x24000);
    func_0015B548(func_1ED6E48(&rec, func_0015D1F0, 0));
    if (func_0015B558() != 0) {
        *(s32 *)(s + 0x10) = 0x39;
        if (*(s32 *)(s + 0x14) == 0) {
            *(s32 *)(s + 0x14) = 0x39;
        }
        ret = 0;
    }
    return ret;
}
