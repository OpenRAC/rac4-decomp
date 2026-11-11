/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Item Item;
struct Item {
    char _p0[0xC];
    s32 fC;
    s32 f10;
};

typedef struct List {
    s32 count;
    Item **items;
} List;

typedef struct Dest {
    s32 f0;
    s32 f4;
} Dest;

typedef struct Obj {
    s32 f0;
    List *list;
    s32 f8;
    Dest *dest;
} Obj;

extern s32 func_L00_00516FC0(Dest *, s32);
extern void func_L00_00535E08(void *, s32, s32, s32, s32);
extern s32 func_L00_00535FB0(s32, s32, s32);
extern s32 func_L00_00546458(Item *arg0, s32 *arg1);

s32 func_L00_00536448(Obj *arg0) {
    s32 buf[4];
    s32 i;
    s32 sub;
    s32 total;
    s32 key;
    Item *head;
    Item *item;
    List *list;
    Dest *dest;
    s32 size;

    sub = 0;
    total = 0;
    key = 0;
    head = 0;
    list = arg0->list;
    for (i = 0; i < list->count; i++) {
        item = list->items[i];
        if (head == 0) {
            head = item;
            sub = 0;
        }
        if (item->fC != key) {
            total += func_L00_00535FB0(1, sub, 0x11);
            head->f10 = sub;
            head = item;
            sub = 0;
            key = item->fC;
        }
        sub += func_L00_00546458(item, 0);
    }
    total += func_L00_00535FB0(1, sub, 0x11);
    if (head != 0) {
        head->f10 = sub;
    }
    size = func_L00_00535FB0(1, total, 0x10);
    dest = arg0->dest;
    if (func_L00_00516FC0(dest, size) != 0) {
    buf[0] = dest->f4;
    func_L00_00535E08(buf, 1, total, 0x10, 0);
    key = -1;
    for (i = 0; i < list->count; i++) {
        item = list->items[i];
        if (key != item->fC) {
            key = item->fC;
            func_L00_00535E08(buf, 1, item->f10, 0x11, 0);
        }
        func_L00_00546458(item, buf);
    }
    arg0->f8 = 0;
    return size;
    }
    return -1;
}
