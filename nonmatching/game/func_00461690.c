/* Not matching yet: BYTES 0/176, exact only with inline asm (plzcw and blezl/sub abs), which matched C may not use (tools/check_func.py func_00461690). Not part of the build. */
#include "common.h"

typedef struct SpriteRec {
    u64 f0;
    s16 h;
    s16 w;
    u8 log_a;
    u8 log_b;
    s16 kind;
} SpriteRec;

extern SpriteRec D_00237D40[];
extern s32 D_00221208;

/* Retail's abs is `blezl x; sub x, $0, x`, which GCC never emits (its abs is bltzl + negu). */
static inline s32 abs_s32(s32 x)
{
    __asm__(".set push
	.set noreorder
	blezl %0, 1f
	sub %0, $0, %0
	.set pop
1:" : "+r"(x));
    return x;
}

/* plzcw (R5900 MMI): leading sign bits minus one, so 30 - n is floor(log2(x)) for x > 0. No C form
 * gives retail's bare plzcw: SN's __builtin_plzcw works on 128-bit values and adds por copies and a
 * sign extension. */
static inline s32 lead_sign_bits(s32 x)
{
    s32 r;
    __asm__("plzcw %0, %1" : "=r"(r) : "r"(x));
    return r;
}

void func_00461690(s32 *src, s32 n)
{
    SpriteRec *r = D_00237D40;

    for (D_00221208 = 0; D_00221208 < n; D_00221208++, r++) {
        s32 w = *src++ >> 6;
        s32 h = *src++ >> 6;
        s32 a = *src++;
        s32 b = *src++;

        r->w = w;
        r->h = h;
        r->kind = 0x13;
        if (a < 0) {
            r->kind = 0x14;
            a = abs_s32(a);
            b = abs_s32(b);
        }
        r->log_a = 30 - lead_sign_bits(a);
        r->log_b = 30 - lead_sign_bits(b);
        r->f0 = 0;
    }
}
