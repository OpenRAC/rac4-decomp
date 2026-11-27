/* Not matching yet: BYTES 13/184 (tools/try_func.py func_01F0443C --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 -mno-split-addresses -falign-loops=1 */
typedef struct {
    s32 unk0[2];
    u8 pad[0x200 - 8];
    s32 unk200;
} Type1;

extern s32 func_01F0410C(Type1 *arg0);
extern s32 func_01F0414C(s32 *arg0, s32 arg1);
extern void func_01F0C090(char *arg0, s32 arg1);
extern s32 D_0019E050[];

s32 func_01F0443C(Type1 *arg0, s32 arg1)
{
    s32 i;
    s32 *p;

    if (arg0->unk200 >= 0x41)
        func_01F0C090((char *)D_0019E050, 0x7D);
    if (arg1 == 0)
        func_01F0C090((char *)D_0019E050, 0x7E);

    i = 0;
    if (arg0->unk200 > 0) {
        p = (s32 *)arg0;
        for (; i < arg0->unk200; i++, p += 2) {
            if (func_01F0414C(p, arg1) != 0)
                return func_01F0410C((Type1 *)p);
        }
    }
    return 0;
}
