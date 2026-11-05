/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Key { s32 len; s32 pad4; s32 data; } Key;
typedef struct Item { s32 pad0; s32 sub; Key *key; s32 val; } Item;
typedef struct List { s32 count; Item **items; } List;
typedef struct Obj { s32 pad0; List *list; } Obj;

extern s32 func_0011A2DC(s32 a, s32 b, s32 n);
extern s32 func_L00_0051CC98(s32 a, s32 b);

s32 func_L00_0052D4C0(Obj *a, Obj *b) {
    s32 i;
    s32 d;
    Item *x;
    Item *y;

    if (a->list->count != b->list->count) {
        return a->list->count - b->list->count;
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = x->key->len - y->key->len;
        if (d != 0) {
            return d;
        }
        d = func_0011A2DC(x->key->data, y->key->data, x->key->len);
        if (d != 0) {
            return d;
        }
        d = x->val - y->val;
        if (d != 0) {
            return d;
        }
    }
    for (i = a->list->count - 1; i >= 0; i--) {
        x = a->list->items[i];
        y = b->list->items[i];
        d = func_L00_0051CC98(x->sub, y->sub);
        if (d != 0) {
            return d;
        }
    }
    return 0;
}
