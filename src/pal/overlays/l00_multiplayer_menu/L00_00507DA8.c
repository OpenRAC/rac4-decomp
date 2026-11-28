/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

typedef struct Type1 Type1;
typedef struct Type2 Type2;
typedef struct HashTable HashTable;

struct Type1 {
    u8 pad[0x1C];
    HashTable *f1C;
    u8 pad20[0x24];
    void (*f44)(Type1 *, Type2 *);
};

struct Type2 {
    u8 pad[0x8C];
    s32 f8C;
};

extern void *func_L00_004F9028(HashTable *, void *);
extern void func_L00_00508168(Type1 *, Type2 *);
extern void func_L00_00507E38(Type2 *);

// Removes a node from the lookup table and list, notifies a callback, and releases it.
s32 func_L00_00507DA8(Type1 *arg0, Type2 *arg1)
{
    s32 removed = 0;
    Type2 *node = func_L00_004F9028(arg0->f1C, arg1);

    if (node != NULL) {
        removed = 1;
        func_L00_00508168(arg0, arg1);
    }

    if (removed) {
        node->f8C = 1;
        if (arg0->f44 != NULL) {
            arg0->f44(arg0, node);
        }
        func_L00_00507E38(node);
    }

    return removed;
}
