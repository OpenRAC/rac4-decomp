/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s8 f0[0x14];
    u8 f14[0x200];
    s32 f214;
    u16 f218;
};
extern s32 func_01EA97E0(u8 *arg0, s32 arg1);
extern s32 func_01EA9928(u8 *arg0, s32 arg1);
extern u16 D_00167F90[];

/* Stamps the entry with a running counter, then packs the name into its byte table. */
s32 func_01EA80F8(Type1 *arg0, s8 *arg1) {
    u16 *counter;
    u16 i;
    u8 *s2;
    u8 *temp;
    s32 s0;
    s32 s5;
    s32 s6;
    s8 c;

    s2 = arg0->f14;
    counter = D_00167F90;
    arg0->f218 = (*counter)++;
    func_01EA9928(s2, arg0->f218);
    func_01EA9928(s2 + 2, 0x100);
    func_01EA9928(s2 + 4, 1);
    func_01EA9928(s2 + 6, 0);
    func_01EA9928(s2 + 8, 0);
    func_01EA9928(s2 + 10, 0);

    s0 = 0xD;
    s5 = 0;
    s6 = 0xC;
    i = 1;
    do {
        c = *arg1;
        if (c == 0x2E) {
            func_01EA97E0(s2 + s6, s5 & 0xFF);
            s6 = s0;
            s5 = 0;
            s0 += 1;
        } else if (c == 0) {
            func_01EA97E0(s2 + s6, s5 & 0xFF);
            func_01EA97E0(s2 + s0, 0);
            s0 += 1;
            break;
        } else {
            func_01EA97E0(s2 + s0, (u8) *arg1);
            s5 += 1;
            s0 += 1;
        }
        i++;
        arg1++;
    } while (i < 0x100);

    temp = s2 + s0;
    s0 += 2;
    func_01EA9928(temp, 1);
    func_01EA9928(s2 + s0, 1);
    s0 += 2;
    arg0->f214 = s0;
    return 0;
}
