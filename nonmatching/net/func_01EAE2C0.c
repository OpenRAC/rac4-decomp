/* Not matching yet: BYTES 123/160 (tools/try_func.py func_01EAE2C0 --diff). Not part of the build. */
/* cflags: @ee296 -O2 -G0 */
typedef struct { u32 unk0; u32 unk4; u32 unk8; u8 S[256]; } State;

extern u32 D_FCFDFEFF[];
extern u32 D_FBFBFBFC[];

void func_01EAE2C0(State *s, u8 *key) {
    u32 n;
    u32 *p;
    u8 j;
    u8 k;
    u8 t;
    u8 tmp;
    u32 v = (u32)D_FCFDFEFF;
    u32 inc = (u32)D_FBFBFBFC;

    p = (u32 *)s->S;
    for (n = 0x100; n != 0; n -= 4) {
        *p = v;
        p++;
        v += inc;
    }
    j = 0;
    k = 0;
    n = 0;
    do {
        t = s->S[n];
        j += key[k];
        k = (k + 1) & 0x3F;
        j += t;
        tmp = s->S[j];
        s->S[j] = t;
        s->S[n] = tmp;
        n = (n + 3) & 0xFF;
    } while (n != 0);
    s->unk0 = 0;
    s->unk4 = 0;
    s->unk8 = 0;
}
