/* Not matching yet: BYTES 6/160 (tools/try_func.py func_L00_00541CF8 --diff). Not part of the build. */
/* cflags: @ee29 -O2 -G0 */
typedef struct List List;
typedef struct Item {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
    List *f10;
} Item;

struct List {
    s32 count;
    Item **items;
};

typedef struct Owner {
    s32 f0;
    s32 f4;
    List *f8;
} Owner;

extern s32 func_L00_005081E0(List *list, Item *item);
extern Item *func_L00_00541B60(s32 id);
extern void func_L00_00541BE0(Item *item);

Item *func_L00_00541CF8(Owner *owner, s32 id) {
    Item *item;
    List *list;
    Item **items;
    s32 count;
    s32 i;

    i = 0;
    list = owner->f8;
    count = list->count;
    if (count > 0) {
        items = list->items;
loop:
        item = items[i];
        i++;
        if (id == item->f8) {
            return item;
        }
        if (i < count) goto loop;
    }
    item = func_L00_00541B60(id);
    if (item == 0) {
        return 0;
    }
    item->f10 = (List *)owner;
    if (func_L00_005081E0(owner->f8, item) != 0) {
        return item;
    }
    func_L00_00541BE0(item);
    return 0;
}
