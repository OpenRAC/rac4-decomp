/* Not matching yet: SIZE ours 140 / retail 136 (tools/try_func.py func_01EAE460 --diff). Not part of the build. */
void func_01EAE460(u8 *c, u8 *p, s32 n) {
    u8 *s;
    u8 i;
    u8 j;
    u8 a;
    u8 b;
    u8 k;

    s = c + 0xC;
    i = c[4];
    *(u32 *)c = *(u32 *)c + n;
    j = c[8];
    do {
        i = i + 5;
        n = n - 1;
        i = i & 0xFF;
        a = s[i];
        j = (j + a) & 0xFF;
        b = s[j];
        s[j] = a;
        s[i] = b;
        a = (a + b) & 0xFF;
        k = *p;
        b = s[k];
        a = s[a];
        j = (j + b) & 0xFF;
        *p++ = a ^ k;
    } while (n != 0);
    c[4] = i;
    c[8] = j;
}
