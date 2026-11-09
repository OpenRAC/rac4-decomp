/* cflags: @ee29 -O2 -G0 */
#include "common.h"

typedef struct Type1 Type1;
struct Type1 {
    s32 f0;
    s32 f4;
    s32 f8;
    s32 fC;
};

void func_L00_004F84C8(s32, s32, s32, s32, s32);
s32 func_L00_00518C68(s32, s32, s32);
Type1 *func_L00_0051CEB0(void);
s32 func_L00_0051CF60(s32);
void func_L00_0051D000(Type1 *);
s32 func_L00_00526868(s32, s32, s32);

Type1 *func_L00_00518B20(s32 arg0, Type1 **arg1, s32 arg2, s32 arg3) {
    Type1 *obj;
    s32 type;
    s32 res;

    if (arg1 != NULL && *arg1 != NULL) {
        obj = *arg1;
    } else {
        obj = func_L00_0051CEB0();
        if (obj == NULL) {
            func_L00_004F84C8(0xD, 0x9B, 0x806, 0, 0);
            return NULL;
        }
    }
    obj->f4 = arg0;
    type = func_L00_0051CF60(arg0);
    obj->f0 = type;
    switch (type) {
    case 6:
        res = func_L00_00526868(0, arg2, arg3);
        obj->fC = res;
        break;
    case 0x74:
        res = func_L00_00518C68(0, arg2, arg3);
        obj->fC = res;
        break;
    default:
        func_L00_004F84C8(0xD, 0x9B, 0x8F, 0, 0);
        goto fail;
    }
    if (res == 0) {
        func_L00_004F84C8(0xD, 0x9B, 0x80D, 0, 0);
        goto fail;
    }
    if (arg1 != NULL) {
        *arg1 = obj;
    }
    return obj;
fail:
    if (arg1 == NULL || *arg1 != obj) {
        func_L00_0051D000(obj);
    }
    return NULL;
}
