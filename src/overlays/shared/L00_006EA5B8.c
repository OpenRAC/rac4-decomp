#include "common.h"

typedef int s128 __attribute__((mode(TI)));
typedef struct { u8 pad[0x86]; s16 type; } Sub;
typedef struct { s128 data; u8 pad0[0x50-0x10]; Sub *sub; u8 pad1[0x390-0x54]; u8 f390[0x10]; } Child;
typedef struct { u8 pad[0x2C88]; s32 b[8]; s32 a[8]; s32 index; s32 count; u8 pad2[0x2EFC-0x2CD0]; Child *child; } Root;
void func_L00_005EB300(void *, void *);
void func_L00_005EE078(s128, void *);
void func_L00_005EE170(s128, void *);
/* Pushes the child's current sample into two ring buffers and advances the ring index. */
void func_L00_006EA5B8(Root *root) {
    s128 value;
    if (root->child->sub->type != 0x21) {
        func_L00_005EB300(root->child->f390, &value);
        func_L00_005EE078(value, &root->a[root->index]);
        func_L00_005EE170(root->child->data, &root->b[root->index]);
        root->index = (root->index + 1) % 8;
        root->count = root->count + 1 < 9 ? root->count + 1 : 8;
    }
}
