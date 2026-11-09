/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Ctx Ctx;
typedef s32 (*Cb)(s32, Ctx *);

typedef struct {
    s32 pad[4];
    Cb cb;
} Cfg;

typedef struct {
    s32 pad[4];
    s32 done;
} Item;

typedef struct {
    s32 count;
    s32 items;
} List;

struct Ctx {
    Cfg *cfg;
    s32 pad[6];
    List *list;
    s32 idx;
    s32 code;
    Item *item;
};

extern u8 func_L00_0052E194[];
s32 func_0052D4A0(Item *);
s32 func_0052D728(Item *);
s32 func_L00_00508600(Item *);
s32 func_L00_0052D4C0(s32, s32);
s32 func_L00_0052D6C0(Item *);
s32 func_L00_0052D718(Item *);
s32 func_L00_0052DEE0(Item *, s32);
s32 func_L00_00541F08(s32);

s32 func_L00_0052E668(Ctx *ctx) {
    Cb cb;
    List *list;
    s32 idx;
    Item *prev;
    Item *cur;
    s32 a;
    s32 r;
    s32 ok;

    cb = ctx->cfg->cb;
    list = ctx->list;
    if (cb == NULL) {
        cb = (Cb)(func_L00_0052E194 + 4);
    }
    idx = list->count;
    idx = ctx->idx = idx - 1;
    prev = ((Item **)list->items)[idx];
    a = func_L00_00508600(prev);
    a = func_L00_0052D4C0(a, func_0052D4A0(prev));
    if (!a) {
        cur = prev;
    } else {
        if (idx <= 0) {
            ctx->item = prev;
            ctx->code = 0x15;
            return cb(0, ctx);
        }
        idx--;
        ctx->idx = idx;
        cur = ((Item **)ctx->list->items)[idx];
    }
    while (idx >= 0) {
        ctx->idx = idx;
        if (cur->done == 0) {
            r = func_L00_0052D6C0(prev);
            if (r == 0) {
                ctx->item = prev;
                ctx->code = 6;
                ok = cb(0, ctx);
                if (!ok) {
                    goto out;
                }
            }
            if (func_L00_0052DEE0(cur, r) <= 0) {
                ctx->item = cur;
                ctx->code = 7;
                ok = cb(0, ctx);
                if (!ok) {
                    goto out;
                }
            }
            r = func_L00_00541F08(func_L00_0052D718(cur));
            if (r == 0) {
                ctx->item = cur;
                ctx->code = 0xD;
                ok = cb(0, ctx);
                if (!ok) {
                    goto out;
                }
            }
            if (r > 0) {
                ctx->item = cur;
                ctx->code = 9;
                ok = cb(0, ctx);
                if (!ok) {
                    goto out;
                }
            }
            cur->done = 1;
        }
        r = func_L00_00541F08(func_0052D728(cur));
        if (r == 0) {
            ctx->item = cur;
            ctx->code = 0xE;
            ok = cb(0, ctx);
            if (!ok) {
                goto out;
            }
        }
        if (r < 0) {
            ctx->item = cur;
            ctx->code = 0xA;
            ok = cb(0, ctx);
            if (!ok) {
                goto out;
            }
        }
        ctx->item = cur;
        ok = cb(1, ctx);
        if (!ok) {
            goto out;
        }
        idx--;
        if (idx < 0) {
            break;
        }
        prev = cur;
        cur = ((Item **)ctx->list->items)[idx];
    }
    ok = 1;
out:
    return ok;
}
