/* cflags: @ee29 -O2 -G0 -fno-strict-aliasing */
#include "common.h"

#include "pal/l00_hash_table.h"
#include "pal/menu_session.h"

typedef struct Type2 Type2;
typedef struct Type3 Type3;

extern Type3 *D_00499D04;
extern void *func_0011A518(void *, s32, s32);
extern void func_L00_004F89C8(s32, s32, s32, const char *, s32);
extern Type2 *func_L00_00521408(void);
extern void func_L00_0051B248(Type3 *, PalMenuSession *, s32 *);

// Allocates a session and initializes its defaults and extension data.
PalMenuSession *func_L00_00507998(void)
{
    Type2 *time;
    PalMenuSession *node = func_L00_004FB1D8(sizeof(*node));

    if (node == NULL) {
        func_L00_004F89C8(0x14, 0xBD, 0x21, NULL, 0);
        return NULL;
    }

    func_0011A518(node, 0, sizeof(*node));
    node->f98 = 1;
    node->fA0 = 0x130;
    time = func_L00_00521408();
    node->fC4 = NULL;
    node->fC8 = NULL;
    node->fA8 = time;
    func_L00_0051B248(D_00499D04, node, &node->fBC);
    return node;
}
