/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"
#include "pal/menu_session.h"

typedef struct Type1 Type1;
typedef struct HashTable HashTable;

struct Type1 {
    u8 pad[0x1C];
    HashTable *f1C;
    u8 pad20[0x24];
    void (*f44)(Type1 *, PalMenuSession *);
};

extern void *func_L00_004F9028(HashTable *, void *);
extern void func_L00_00508168(Type1 *, PalMenuSession *);
extern void func_L00_00507E38(PalMenuSession *);

// Removes a node from the lookup table and list, notifies a callback, and releases it.
s32 func_L00_00507DA8(Type1 *arg0, PalMenuSession *arg1)
{
    s32 removed = 0;
    PalMenuSession *node = func_L00_004F9028(arg0->f1C, arg1);

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
