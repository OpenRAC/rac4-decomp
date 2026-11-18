/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct { s32 v; } __attribute__((packed)) PU32;
typedef struct { u8 b[0xB0]; } Body;

extern s32 D_21D9A0[];

/* Copies a 0xB4-byte record from arg3 into a stack buffer, sets its two callback fields, calls the handler in D_21D9A0 with it, and returns the record's first word. */
s32 func_01EA93B8(s32 a0, s32 a1, s32 a2, u8 *arg3) {
    Body buf;
    PU32 hdr;
    void (*fn)(void *);
    s32 *tbl;

    hdr = *(PU32 *)arg3;
    buf = *(Body *)(arg3 + 4);

    tbl = D_21D9A0;
    fn = (void (*)(void *))tbl[2];
    if (fn != 0) {
        *(s32 *)(buf.b + 0xA8) = (s32)(arg3 + 0xB4);
        *(s32 *)(buf.b + 0xAC) = tbl[3];
        fn(&buf);
    }
    return hdr.v;
}
