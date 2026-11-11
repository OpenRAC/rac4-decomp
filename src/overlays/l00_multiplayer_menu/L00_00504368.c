/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C8568 (src/levels/39_multiplayer_menu/L39_004C8568.c, GPL-3.0), the same code in both games. */

typedef struct M_004C8568 { char pad[0x1C]; s32 (*fn)(void *, s32, u8 *); } M_004C8568;
typedef struct T_004C8568 { char pad[0x54]; M_004C8568 *m; } T_004C8568;
typedef struct K_004C8568 { s32 type; s32 f4; char pad[4]; s32 fC; } K_004C8568;
typedef struct C_004C8568 {
    char pad0[8]; T_004C8568 *meth;
    char pad1[0x24]; s32 state;
    char pad2[8]; struct { s32 f0; u8 *data; } *buf;
    s32 f40; s32 f44;
    char pad3[0xC]; char *s3;
    char pad4[0x2C]; struct { s32 f0; struct { s32 f0; K_004C8568 *key; } *p; } *cert;
} C_004C8568;
extern s32 func_L00_00526738(s32, u8 *, u8 *, s32 *, s32);
extern s32 func_L00_00519738(s32, u8 *, s32, u8 *, s32 *, s32);
extern void func_L00_004F84C8(s32, s32, s32, s32, s32);
extern s32 func_L00_00505F80(C_004C8568 *, s32);
s32 func_L00_00504368(C_004C8568 *s) {
    u8 data[0x30];
    s32 j;
    u8 *p;
    u8 *d;
    K_004C8568 *pkey;
    s32 i;
    u64 n;
    if (s->state == 0x1190) {
        d = s->buf->data;
        p = d + 4;
        pkey = s->cert->p->key;
        if (s->meth->m->fn(s, *(s32 *)(s->s3 + 0xFC), &data[0x10]) == 0) goto err;
        if (pkey->type == 6) {
            if (s->meth->m->fn(s, *(s32 *)(s->s3 + 0xF8), data) == 0) goto err;
            i = func_L00_00526738(0x24, data, d + 6, (s32 *)pkey->fC, 1);
            if (i <= 0) {
                func_L00_004F84C8(0x14, 0x9A, 0x804, 0, 0);
                goto err;
            }
            d[4] = i >> 8;
            p[1] = i;
            n = i + 2;
        } else if (pkey->type == 0x74) {
            if (!func_L00_00519738(pkey->f4, &data[0x10], 0x14, d + 6, &j, pkey->fC)) {
                func_L00_004F84C8(0x14, 0x9A, 0x80A, 0, 0);
                goto err;
            }
            d[4] = j >> 8;
            p[1] = j;
            n = j + 2;
        } else {
            func_L00_004F84C8(0x14, 0x9A, 0x9D, 0, 0);
            goto err;
        }
        *d++ = 0xF;
        d[0] = (u8)((n >> 16) & 0xFF);
        d[1] = (u8)((n >> 8) & 0xFF);
        d[2] = (u8)(n & 0xFF);
        s->f40 = (s32)n + 4;
        s->f44 = 0;
    }
    return func_L00_00505F80(s, 0x16);
err:
    return -1;
}
