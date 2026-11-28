/* cflags: @ee296 -O2 -G0 */
#include "common.h"

typedef struct Node Node;
typedef struct Type2 Type2;
typedef struct Type3 Type3;

extern s32 func_003FD5F8(Node *);
extern s32 func_L00_00533318(Type2 *);
extern s32 func_L00_00543A08(Node *, Type2 *, Type3 **, s32);
extern s32 func_L00_00543AC8(Node *, Type2 *, Type3 **, s32);

/* Validate both inputs and forward the request when both checks pass. */
s32 func_L00_00532D80(Node *arg0, Type2 *arg1, Type3 **arg2, s32 arg3) {
    s32 result = func_003FD5F8(arg0);

    if (result != 0) {
        return result;
    }

    result = func_L00_00533318(arg1);
    if (result != 0) {
        return result;
    }

    return func_L00_00543A08(arg0, arg1, arg2, arg3);
}

/* Validate both inputs and forward the request when both checks pass. */
s32 func_L00_00532FA8(Node *arg0, Type2 *arg1, Type3 **arg2, s32 arg3) {
    s32 result = func_003FD5F8(arg0);

    if (result != 0) {
        return result;
    }

    result = func_L00_00533318(arg1);
    if (result != 0) {
        return result;
    }

    return func_L00_00543AC8(arg0, arg1, arg2, arg3);
}
