/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Type1 {
    u64 d[12];
} Type1;

extern void func_01EAE980(void *);
extern void *func_01EAEA48(void *, const void *, s32);
extern void func_01EAEBE0(void *ctx, void *out, u32 len);
extern void func_01EB1C20(void *arg0);
extern void *func_01EB1C60(void *, const void *, s32);
extern void func_01EB1DC0(void *, void *);
extern s32 D_0019A488[];
extern s32 D_0019A490[];
extern s32 D_0019A498[];

/* Builds three records from the input blocks and hands each to the handler at arg0 with its own key. */
void func_01EE0E50(u8 *arg0, u8 *arg1, u8 *arg2, u8 *arg3)
{
    Type1 sp0;
    Type1 sp60;
    Type1 spC0;
    u8 sp120[0x14];
    Type1 *p;

    func_01EB1C20(&sp0);
    func_01EB1C60(&sp0, arg1, 0x30);

    sp60 = sp0;
    p = &sp60;
    func_01EAE980(&spC0);
    func_01EAEA48(&spC0, D_0019A488, 1);
    func_01EAEA48(&spC0, arg1, 0x30);
    func_01EAEA48(&spC0, arg2, 0x20);
    func_01EAEA48(&spC0, arg3, 0x20);
    func_01EAEBE0(&spC0, sp120, 0x14);
    func_01EB1C60(p, sp120, 0x14);
    func_01EB1DC0(arg0, p);

    *p = sp0;
    func_01EAE980(&spC0);
    func_01EAEA48(&spC0, D_0019A490, 2);
    func_01EAEA48(&spC0, arg1, 0x30);
    func_01EAEA48(&spC0, arg2, 0x20);
    func_01EAEA48(&spC0, arg3, 0x20);
    func_01EAEBE0(&spC0, sp120, 0x14);
    func_01EB1C60(p, sp120, 0x14);
    func_01EB1DC0(arg0 + 0x10, p);

    *p = sp0;
    func_01EAE980(&spC0);
    func_01EAEA48(&spC0, D_0019A498, 3);
    func_01EAEA48(&spC0, arg1, 0x30);
    func_01EAEA48(&spC0, arg2, 0x20);
    func_01EAEA48(&spC0, arg3, 0x20);
    func_01EAEBE0(&spC0, sp120, 0x14);
    func_01EB1C60(p, sp120, 0x14);
    func_01EB1DC0(arg0 + 0x20, p);
}
