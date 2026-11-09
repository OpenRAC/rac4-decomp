/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct {
    unsigned long *d;
    int top;
    int dmax;
    int neg;
    int flags;
} Type1;

typedef struct {
    int tos;
    Type1 bn[12];
} Type2;

extern Type1 *func_L00_00538190(void);
extern void func_L00_00538038(Type1 *a);
extern int func_L00_00538508(Type1 *a, unsigned long w);
extern Type1 *func_L00_005383D0(Type1 *a, Type1 *b);
extern int func_L00_005466E8(Type1 *dv, Type1 *rm, Type1 *m, Type1 *d, Type2 *ctx);
extern int func_L00_00538DE0(Type1 *r, Type1 *a, Type1 *b, Type2 *ctx);
extern int func_L00_005377B0(Type1 *r, Type1 *a, Type1 *b);
extern int func_L00_00537BB0(Type1 *r, Type1 *a, Type1 *b);
extern int func_L00_00537CE8(Type1 *r, Type1 *m, Type1 *d, Type2 *ctx);

Type1 *func_L00_00537D20(Type1 *in, Type1 *a, Type1 *n, Type2 *ctx) {
    Type1 *A, *B, *X, *Y, *M, *D, *R, *T;
    Type1 *ret = 0;
    int sign;

    A = &ctx->bn[ctx->tos];
    B = &ctx->bn[ctx->tos + 1];
    X = &ctx->bn[ctx->tos + 2];
    D = &ctx->bn[ctx->tos + 3];
    M = &ctx->bn[ctx->tos + 4];
    Y = &ctx->bn[ctx->tos + 5];
    ctx->tos += 6;
    if (in == 0)
        R = func_L00_00538190();
    else
        R = in;
    if (R == 0) goto err;

    func_L00_00538508(X, 0);
    func_L00_00538508(Y, 1);
    if (func_L00_005383D0(A, a) == 0) goto err;
    if (func_L00_005383D0(B, n) == 0) goto err;
    sign = 1;

    while (!((B->top == 0) || ((B->top == 1) && (B->d[0] == 0)))) {
        if (!func_L00_005466E8(D, M, A, B, ctx)) goto err;
        T = A;
        A = B;
        B = M;
        if (!func_L00_00538DE0(T, D, X, ctx)) goto err;
        if (!func_L00_005377B0(T, T, Y)) goto err;
        M = Y;
        Y = X;
        X = T;
        sign = -sign;
    }
    if (sign < 0) {
        if (!func_L00_00537BB0(Y, n, Y)) goto err;
    }

    if ((A->top == 1) && (A->d[0] == 1)) {
        if (!func_L00_00537CE8(R, Y, n, ctx)) goto err;
    } else {
        goto err;
    }
    ret = R;
err:
    if ((ret == 0) && (in == 0)) func_L00_00538038(R);
    ctx->tos -= 6;
    return ret;
}
