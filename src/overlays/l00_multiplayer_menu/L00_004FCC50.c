/* cflags: @ee29 -O2 -G0 */
#include "common.h"
/* Ported from rac3-decomp's func_L39_004C0E50 (src/levels/39_multiplayer_menu/L39_004C0E50.c, GPL-3.0), the same code in both games. */

typedef struct C_004C0E50 {
    s32 length;
    u8 *data;
} C_004C0E50;
typedef struct E_004C0E50 {
    u8 _00[0x90];
    s32 conn_id_length;
    u8 conn_id[16];
} E_004C0E50;
typedef struct Type1 {
    u8 _00[0x30];
    s32 state;
    u8 _34[0x3C - 0x34];
    C_004C0E50 *init_buf;
    s32 init_num;
    s32 init_off;
    u8 _48[0x50 - 0x48];
    E_004C0E50 *s2;
} Type1;
extern void *func_0011A370(void *, const void *, unsigned int);
extern s32 func_L00_00501E20(Type1 *);
s32 func_L00_004FCC50(Type1 *s) {
    u8 *p;
    if (s->state == 0x1040) {
        p = s->init_buf->data;
        *(p++) = 3;
        func_0011A370(p, s->s2->conn_id, (unsigned int)s->s2->conn_id_length);
        s->state = 0x1041;
        s->init_num = s->s2->conn_id_length + 1;
        s->init_off = 0;
    }
    return func_L00_00501E20(s);
}
