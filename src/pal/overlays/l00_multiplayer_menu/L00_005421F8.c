/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct Type3 Type3;
typedef struct Type4 Type4;

struct Type2 {
    u8 pad0[8];
    Type1 *f8;
    u8 padC[4];
    void *f10;
};
struct Type4 {
    s32 f0;
    Type2 **f4;
};
struct Type3 {
    u8 pad0[8];
    void *f8;
};

extern s32 func_L00_005086E0(Type4 *, Type2 *);
extern Type2 *func_L00_00542060(Type1 *);
extern void func_L00_005420E0(Type2 *);

/* Find an item by descriptor, otherwise create it and append it to the owner. */
Type2 *func_L00_005421F8(Type3 *owner, Type1 *descriptor) {
    Type2 *item;
    Type4 *list;
    Type2 **items;
    s32 count;
    s32 i;

    list = owner->f8;
    count = list->f0;
    for (i = 0; i < count; i++) {
        item = list->f4[i];
        if (descriptor == item->f8) {
            return item;
        }
    }
    item = func_L00_00542060(descriptor);
    if (item == 0) {
        return 0;
    }
    item->f10 = owner;
    if (func_L00_005086E0(owner->f8, item) != 0) {
        return item;
    }
    func_L00_005420E0(item);
    return 0;
}
