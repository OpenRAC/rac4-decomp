/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { u8 S[256]; u8 i; u8 j; } Rc4;
void func_01EAE190(Rc4 *s, u8 *key, u32 len) {
    u32 n;
    u8 j;
    u8 k;
    u8 t;
    for (n = 0; n < 256; n++) {
        s->S[n] = n;
    }
    s->i = 0;
    s->j = 0;
    k = 0;
    j = 0;
    for (n = 0; n < 256; n++) {
        t = s->S[n];
        j += t + key[k];
        s->S[n] = s->S[j];
        s->S[j] = t;
        k = (k + 1) % len;
    }
}
