#include "common.h"
typedef struct { int a[7]; } Value;
typedef struct { char pad[0xd0]; char flag; char pad2[3]; Value value; } Object;
typedef struct { char pad[0x3c]; Object *object; } Root;
extern Root *D_002233A4;
/* Clear the flag and copy the seven-word value. */
void func_L00_0076C590(Value *arg0) {
    Object *obj = D_002233A4->object;
    obj->flag = 0;
    obj->value = *arg0;
}
